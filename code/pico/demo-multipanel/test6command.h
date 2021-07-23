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
        //canvas->drawText(1,20, "192.168.20.234", true); 
        canvas->drawText(0, 0, "Roses are red", true);
        canvas->drawText(0, 8, "Violets are blue", true);
        canvas->drawText(0, 16, "You know I got", true);
        canvas->drawText(0, 24, "My eyes on YOU!", true);
        canvas->setFont(defaultFont);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
