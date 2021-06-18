#pragma once

#include "command.h"

class Test4Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 10000) {        
        clearSerialMonitor();
        canvas->clear();
        canvas->setPixel(0,0);
        canvas->setPixel(16,0);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
