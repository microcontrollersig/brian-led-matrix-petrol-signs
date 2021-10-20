#pragma once

#include "command.h"



class TestSimpleScrollCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char text1[200];
    char text2[200];
    int fontIndex = 0;
    int x = 0;
    int y = 0;

    int currentScrollX = 0;
    int scrollTextSize = 0;

    int counter = 0;
    bool scrollingMode = false;
    int timeOutMs = 60;
      
  public:  
    DMD3 *scrollingCanvas;

    TestSimpleScrollCommand() {
      scrollingCanvas = new DMD3(40,1);
      scrollingCanvas->setFont(VerdanaFont16x16);
      scrollingCanvas->clear();
    
    }
    
    void parseArgs(std::vector<std::string> args) override {  
      std::stringstream ss1, ss2, ss3, ss4;
      memset(text1, 0, sizeof(text1));
      memset(text2, 0, sizeof(text2));      
      ss1 << args.at(0);
      ss1 >> x;
      ss2 << args.at(1);
      ss2 >> y;
      strcpy(text1, args.at(2).c_str());      
      strcpy(text2, args.at(3).c_str());
      ss3 << args.at(4);
      ss3 >> fontIndex; 
      
      scrollingCanvas->drawText(96,0,text2);      
      scrollTextSize = 16 * strlen(text2) + 106;
    }
    
    void execute(DMD3 *canvas)  override {
     
    
      if ( millis() - timeStart > 60) {        
        clearSerialMonitor();
        canvas->clear();        
        canvas->drawText(x,y,text1);      
        scrollingCanvas->copy(currentScrollX,0,96,16,canvas,0,16);
        printCanvas(canvas);
        canvas->update();
        if (currentScrollX++ > scrollTextSize ) {
          currentScrollX = 0;
        }
        timeStart = millis();
        }
    }
};
