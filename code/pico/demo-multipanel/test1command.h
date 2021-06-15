#pragma once

#include "command.h"

class Test1Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 10000) {  
        clearSerialMonitor();
        canvas->clear();
        for (int i=0; i<6; i++) {
          canvas->setPixel(16*i, 0);
          canvas->setPixel(16*i + 15, 0);
          canvas->setPixel(16*i, 15);
          canvas->setPixel(16*i + 15, 15);          
        }

        for (int i=0; i<6; i++) {
          canvas->setPixel(16*i, 16);
          canvas->setPixel(16*i + 15, 16);
          canvas->setPixel(16*i, 31);
          canvas->setPixel(16*i + 15, 31);        
        }
        
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
