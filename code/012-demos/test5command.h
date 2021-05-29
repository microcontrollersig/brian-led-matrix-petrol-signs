#pragma once

#include "command.h"

enum class Test5Modes
{
  Horizontal,
  Vertical
};

class Test5Command : public Command
{
  private:
    Test5Modes mode = Test5Modes::Horizontal;
    int i = 0;
    int j = 0;
    unsigned long timeStart = 0;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 50) {
        clearSerialMonitor();
        canvas->clear();

        int width = 16;
        int height = 16;

        char buf[100];

        switch(mode) {
          case Test5Modes::Horizontal:
            if ((j % 2) == 1)
              canvas->setPixel(width - i - 1, j);
            else
              canvas->setPixel(i,j);
            for (int z=0; z< height; z++) {
              canvas->debugPixelLine(z, buf);
              Serial.println(buf);    
            } 
            i = i + 1;
            if (i == 16) {
              i=0;
              j = j+1;
            }
            if (j == 16) {
              i=0;
              j=0;
              mode = Test5Modes::Vertical;
            }
            break;                    
          case Test5Modes::Vertical:
            if ((i % 2) == 1)
              canvas->setPixel(i, height - j -1);
            else
              canvas->setPixel(i,j);
            for (int z=0; z< height; z++) {
              canvas->debugPixelLine(z, buf);
              Serial.println(buf);    
            } 
            j = j + 1;
            if (j == 16) {
              j=0;
              i = i+1;
            }
            if (i == 16) {
              i=0;
              j=0;
              mode = Test5Modes::Horizontal;
            }
            break;         
      }
  
      timeStart = millis();
      }
    }    
};
