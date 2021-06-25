#pragma once

#include "command.h"

class TestIdleCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 3000) { 
        clearSerialMonitor();
        canvas->clear();
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
