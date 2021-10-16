#pragma once

#include "command.h"

class Test11Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
    DMD3 *scrollingCanvas;
    int currentScrollX = 0;
    int scrollTextSize = 0;
  
  public:
    Test11Command() {
      scrollingCanvas = new DMD3(40,1);
      scrollingCanvas->setFont(VerdanaFont16x16);
      scrollingCanvas->clear();
      scrollingCanvas->drawText(96,0,"AND A HAPPY NEW YEAR");      
      scrollTextSize = 16 * sizeof("AND A HAPPY NEW YEAR") + 106;      
    }

    void print(uint8_t *data) 
{
  Serial.print(" 0x");
  Serial.print(*data >> 4, HEX);
  Serial.print(*data & 0x0F, HEX); 
}

    void printScrollingCanvas(DMD3 *canvas)
    {
      if (DEBUG)
      {
        char buf[100];
        for (int i=0; i < 32; i++) 
        {
          scrollingCanvas->debugPixelLine(i, buf);
          Serial.println(buf);    
        }
      } 
    }
  
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 60) {        
        clearSerialMonitor();
        canvas->clear();        
        canvas->drawText(8,0,"MERRY");
        canvas->drawText(9,16, "XMAS!");
        //scrollingCanvas->copy(currentScrollX,0,96,16,canvas,0,16);
        printCanvas(canvas);
        canvas->update();
        if (currentScrollX++ > scrollTextSize) {
          currentScrollX = 0;
        }
        timeStart = millis();
        
      }
    }
};
