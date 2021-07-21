#pragma once

#include "command.h"

class Test10Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 5000) {  
        clearSerialMonitor();
        canvas->clear();
        Bitmap::Font defaultFont = canvas->font();
        canvas->setFont(SpaceInvadersFont16x16);
        char c = 69;
        canvas->drawChar(0,0, c); 
        canvas->setFont(defaultFont);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
