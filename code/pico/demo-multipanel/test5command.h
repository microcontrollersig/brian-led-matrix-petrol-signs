#pragma once
#include "testmode.h"

#include "command.h"


class Test5Command : public Command
{  
  private:
    TestMovingMode mode = TestMovingMode::HORIZONTAL;
    int i = 0;
    int j = 0;
    unsigned long timeStart = 0UL;
    int panelX = 80;
    int panelY = 16;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 3000) {
        clearSerialMonitor();
        canvas->clear();


        for (int i=0; i< 16; i++) {
          for (int j=0; j< 16; j++) {
         canvas->setPixel(panelX + i, panelY + j);  
        }
        }
  

        panelX = panelX - 16;
        if (panelX == -16) {
          panelX = 80;
          if (panelY == 16) {
            panelY = 0;
          }
          else if (panelY == 0) {
            panelY = 16;
          }
          
        }
       
        printCanvas(canvas);
        canvas->update();      
        timeStart = millis();
      }
    }
        
};
