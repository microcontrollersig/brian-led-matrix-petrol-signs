#pragma once

#include "command.h"

class Test4Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
    DMD3 *scrollingCanvas;
    int currentScrollX = 0;
    int scrollTextSize = 0;
  
  public:
    Test4Command() {
      scrollingCanvas = new DMD3(30,1);
      scrollingCanvas->setFont(VerdanaFont16x16);
      scrollingCanvas->clear();
      scrollingCanvas->drawText(0,0,"THREE LETTER ACRONYM");      
      scrollTextSize = 16 * sizeof("THREE LETTER ACRONYM") + 16;
      
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
      if ( millis() - timeStart > 100) {        
        clearSerialMonitor();
        canvas->clear();        
        canvas->drawText(0,0," TLA");
        scrollingCanvas->copy(currentScrollX,0,96,16,canvas,0,16);
        printCanvas(canvas);
        canvas->update();
        if (currentScrollX++ > scrollTextSize) {
          currentScrollX = 0;
        }
        timeStart = millis();
        
      }
    }
};
