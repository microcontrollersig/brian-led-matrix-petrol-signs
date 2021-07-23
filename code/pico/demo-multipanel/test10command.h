#pragma once

#include "command.h"

class Test10Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char currentSpaceInvader = 66;
  
  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 5000) {  
        clearSerialMonitor();
        canvas->clear();
        Bitmap::Font defaultFont = canvas->font();
        canvas->setFont(SpaceInvadersFont16x16);
        for (int i=0; i<6; i++) {
          canvas->drawChar(16*i,0, currentSpaceInvader); 
          canvas->drawChar(16*i,16, currentSpaceInvader + 1); 
        }    
        currentSpaceInvader += 2;

        if (currentSpaceInvader == 86) 
          currentSpaceInvader = 98;
        else if (currentSpaceInvader == 118) 
          currentSpaceInvader = 66;
        canvas->setFont(defaultFont);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
