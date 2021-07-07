#pragma once

#include "command.h"

class TestTwoTextWithFontCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char text1[100];
    char text2[100];
    int fontIndex = 0;
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      strcpy(text1, args.at(0).c_str());
      strcpy(text2, args.at(1).c_str());
      std::stringstream ss;
      ss << args.at(2);
      ss >> fontIndex;   
    }
  
    void execute(DMD3 *canvas)  override {
      if (millis() - timeStart > 5000) {
        clearSerialMonitor();
        canvas->clear();
        switch(fontIndex) {
          case 0:
            canvas->drawText(0,0, text1); 
            canvas->drawText(0,16, text2); 
            break;

          case 1:
            Bitmap::Font defaultFont = canvas->font();
            canvas->setFont(fonts[fontIndex]);
            canvas->drawText(1,4, text1);
            canvas->drawText(1,20, text2);
            canvas->setFont(defaultFont);              
            break;
        }
        printCanvas(canvas);
        canvas->update();    
        timeStart = millis();
      }
    }
};
