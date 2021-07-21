#pragma once

#include "command.h"

class Test8Command : public Command
{  
  private:
    unsigned long timeStart = 0UL;
  
  public:
    void execute(DMD3 *canvas)  override {
      if (millis() - timeStart > 5000) {
      //clearSerialMonitor();
      Serial.print("DEBUG:");
      Serial.print(DEBUG);
      Serial.print(" TIMEOUT:");
      Serial.print(TIMEOUT);
      Serial.print(" BRIGHTNESS:");
      Serial.print(canvas->getBrightness());      
      Serial.println();
      //canvas->clear();
      //printCanvas(canvas);
      //canvas->update();
      timeStart = millis();
      }
    }
};
