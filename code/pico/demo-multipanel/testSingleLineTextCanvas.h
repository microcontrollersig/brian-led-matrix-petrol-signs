#pragma once

#include "command.h"

class TestSingleLineTextCanvasCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char text1[100];
    int fontIndex = 0;
    int x = 0;
    int y = 0;
    bool dirty = false;
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1, ss2, ss3;
      ss1 << args.at(0);
      ss1 >> x;
      ss2 << args.at(1);
      ss2 >> y;
      strcpy(text1, args.at(2).c_str());      
      ss3 << args.at(3);
      ss3 >> fontIndex;   
      dirty = true; 
    }
  
    void execute(DMD3 *canvas)  override {
      if (dirty) {
        clearSerialMonitor();
        switch(fontIndex) {
          case 0:
            canvas->drawText(x,y, text1); 
            break;

          default:
            Bitmap::Font defaultFont = canvas->font();
            canvas->setFont(fonts[fontIndex]);
            canvas->drawText(x,y, text1);
            canvas->setFont(defaultFont);              
            break;
        }
        printCanvas(canvas);
        canvas->update();    
        dirty = false;
      }
    }
};
