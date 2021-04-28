#include "dmd3.h"

DMD3 display(6,1);

void setup()
{
  Serial.begin(115200);
  delay(5000);
  Serial.println("\n\nDraw buffer.....\n\n");
  
  char buf[1000];
  display.setFont(ArialFont16x16);
  //for (int j=0; j<10; j++)
  //display.setPixel(3,j,DMD3::White);
  display.drawChar(0,0,'a' ); 
  display.drawChar(16,0,'b');
  display.drawChar(32,0,'C');
  display.drawChar(48,0,'1');
  display.drawChar(64,0,'2');
  display.drawChar(82,0,'3');
  for (int i=0; i<16; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
  }
  
  
}

void loop()
{

}
