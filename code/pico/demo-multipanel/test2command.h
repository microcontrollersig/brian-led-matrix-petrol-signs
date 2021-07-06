#pragma once

#include "command.h"

class Test2Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > TIMEOUT) {        
        clearSerialMonitor();
        canvas->clear();
        canvas->setPixel(0,0);
        canvas->setPixel(95,0);
        canvas->setPixel(0,31);
        canvas->setPixel(95,31);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
