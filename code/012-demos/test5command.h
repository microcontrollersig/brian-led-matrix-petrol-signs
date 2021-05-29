#pragma once

#include "command.h"

class Test5Command : public Command
{
  private:
    int mode = 0;
    int i = 0;
    int j = 0;
  
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      canvas->clear();

      int width = 16;
      int height = 16;

      switch(mode) {
       case 0:
         break;

       case 1:
         break;         
      }
  
  /*
  for (int j=0; j < height; j++) {
    for (int i=0; i < width; i++) {
      clearSerialMonitor();
      display.clear();
      if ((j % 2) == 1)
      display.setPixel(width - i - 1, j);
      else
        display.setPixel(i,j);
      for (int z=0; z< height; z++) {
        display.debugPixelLine(z, buf);
        Serial.println(buf);    
      }
      delay(30);
    }
  }
*/
/*
  for (int i=0; i < width; i++)  {
    for (int j=0; j < height; j++) {
      clearSerialMonitor();
      display.clear();
      if ((j % 2) == 1)
      display.setPixel(i, height - j - 1);
      else
        display.setPixel(i,j);
      for (int z=0; z< height; z++) {
        display.debugPixelLine(z, buf);
        Serial.println(buf);    
      }
      delay(30);
    }
  }  
  */    
    }
};
