#pragma once

#include "command.h"

class TestIPAddressCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char text[100];
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      //Serial.println(args[0].c_str());
      strcpy(text, args.at(0).c_str());
    }
  
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 10000) {        
        clearSerialMonitor();
        canvas->clear();
        Bitmap::Font defaultFont = canvas->font();
        canvas->setFont(System5x7);
        canvas->drawText(1,20, text, true); 
        canvas->setFont(defaultFont);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
