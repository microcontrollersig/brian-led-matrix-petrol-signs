#pragma once

#include "command.h"

class Test6Command : public Command
{  
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 10000) {       
        clearSerialMonitor();
        canvas->clear();
        Bitmap::Font defaultFont = canvas->font();
        canvas->setFont(System5x7);
        canvas->drawText(1,20, "192.168.20.234", true); 
        canvas->setFont(defaultFont);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
