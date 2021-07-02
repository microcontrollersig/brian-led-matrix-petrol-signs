#pragma once

#include "command.h"

class Test3Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 5000) {  
        clearSerialMonitor();
        canvas->clear();
        canvas->drawText(0,0, "HUMPTY");
        canvas->drawText(0,16, "DUMPTY");
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
