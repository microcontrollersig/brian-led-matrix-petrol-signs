#include "dmd3.h"

//#include "Droid_Sans_24.h"
//#define DroidSansFont10x25 Droid_Sans_24

//#include "digit_16.h"
//#define DigitFont10x16 digit_16

//#include "Arial14.h"
//#define ArialFont10x14 Arial_14

#include "Arial16.h"
#define ArialFont16x16 Arial16x16

DMD3 display(6,1);
//DMD3 display(6,2);

void setup()
{
  Serial.begin(115200);
  delay(5000);
  Serial.println("\n\nDraw buffer.....\n\n");
  
  char buf[1000];
  
  //display.setFont(DroidSansFont10x25);
  //display.setFont(DigitFont10x16);
  //display.setFont(ArialFont10x14);
  display.setFont(ArialFont16x16);
  
  //for (int j=0; j<10; j++)
  //display.setPixel(3,j,DMD3::White);
  
  display.drawChar(0,0,'a' ); 
  display.drawChar(16,0,'b');
  display.drawChar(32,0,'C');
  display.drawChar(48,0,'1');
  display.drawChar(64,0,'2');
  display.drawChar(82,0,'3');
  //display.drawChar(0,0,'4');
  //display.drawChar(16,0,'5');
  //display.drawChar(32,0,'6'); 

  //for (int i=0; i<32; i++) {
  for (int i=0; i<16; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
  }
  
  
}

void loop()
{

}
