#pragma once

#include "command.h"

class Test8Command : public Command
{
  private:
    int fontIndex = 0;
    int currentIndex = 48;
    int fontIndexStart[3];
    int fontIndexEnd[3];
    unsigned long timeStart = 0UL;
  
  public:
    Test8Command() : fontIndexStart{48,65,97}, fontIndexEnd{57,90,122} {}
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 500) {
        clearSerialMonitor();
        canvas->clear();
        canvas->drawChar(0,0, currentIndex);
        printCanvas(canvas);
        if (currentIndex == fontIndexEnd[fontIndex]) {
          fontIndex = (fontIndex + 1) %3;
          currentIndex = fontIndexStart[fontIndex];
        }
        else {
          currentIndex++;  
        }
        canvas->update();
        timeStart = millis();
      }      
    }
};
