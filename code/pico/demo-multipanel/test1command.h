#pragma once

#include "command.h"

class Test1Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 2000) {  
        clearSerialMonitor();
        canvas->clear();
        int width = canvas->width();
        for (int i=0; i< width; i++) {
          //top row outer corners
          canvas->setPixel(16*i + 1, 1);
          canvas->setPixel(16*i + 14, 1);
          canvas->setPixel(16*i + 1, 14);
          canvas->setPixel(16*i + 14, 14); 

          // top row diamond
          canvas->setPixel(16*i + 7, 4);
          canvas->setPixel(16*i + 6, 5);
          canvas->setPixel(16*i + 8, 5);
          canvas->setPixel(16*i + 5, 6);
          canvas->setPixel(16*i + 9, 6);
          canvas->setPixel(16*i + 4, 7);
          canvas->setPixel(16*i + 10, 7);
          canvas->setPixel(16*i + 3, 8);
          canvas->setPixel(16*i + 7, 8);
          canvas->setPixel(16*i + 11, 8);          

          canvas->setPixel(16*i + 7, 12);
          canvas->setPixel(16*i + 6, 11);
          canvas->setPixel(16*i + 8, 11);
          canvas->setPixel(16*i + 5, 10);
          canvas->setPixel(16*i + 9, 10);
          canvas->setPixel(16*i + 4, 9);
          canvas->setPixel(16*i + 10, 9);
        

          // bottom row diamond
          canvas->setPixel(16*i + 7, 4+16);
          canvas->setPixel(16*i + 6, 5+16);
          canvas->setPixel(16*i + 8, 5+16);
          canvas->setPixel(16*i + 5, 6+16);
          canvas->setPixel(16*i + 9, 6+16);
          canvas->setPixel(16*i + 4, 7+16);
          canvas->setPixel(16*i + 10, 7+16);
          canvas->setPixel(16*i + 3, 8+16);
          canvas->setPixel(16*i + 7, 8+16);
          canvas->setPixel(16*i + 11, 8+16);          

          canvas->setPixel(16*i + 7, 12+16);
          canvas->setPixel(16*i + 6, 11+16);
          canvas->setPixel(16*i + 8, 11+16);
          canvas->setPixel(16*i + 5, 10+16);
          canvas->setPixel(16*i + 9, 10+16);
          canvas->setPixel(16*i + 4, 9+16);
          canvas->setPixel(16*i + 10, 9+16);
          //bottom row outer corners

          canvas->setPixel(16*i + 1, 1 + 16);
          canvas->setPixel(16*i + 14, 1 + 16);
          canvas->setPixel(16*i + 1, 14 + 16);
          canvas->setPixel(16*i + 14, 14 + 16);                    
        }

        /*
        for (int i=0; i<6; i++) {
          canvas->setPixel(16*i, 16);
          canvas->setPixel(16*i + 15, 16);
          canvas->setPixel(16*i, 31);
          canvas->setPixel(16*i + 15, 31);        
        }
        */
        
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
