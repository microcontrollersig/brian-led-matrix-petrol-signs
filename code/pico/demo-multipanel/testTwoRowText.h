#pragma once

#include "command.h"

class TestTwoRowTextCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char text1[100];
    char text2[100];
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      strcpy(text1, args.at(0).c_str());
      strcpy(text2, args.at(1).c_str());
    }
  
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 10000) {        
        clearSerialMonitor();
        canvas->clear();
        canvas->drawText(0,0, text1); 
        canvas->drawText(0,16, text2); 
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
