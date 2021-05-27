//#include <Arduino.h>

#include "DMDv3.h"
#include "Arial16.h"

//Old wrong assignments
/*
#define PIN_DATA1 D2
#define PIN_DATA2 D1
#define PIN_DATA3 D6
#define PIN_DATA4 D8
*/


//data4: u18-u21 
//data3: u14-u17
//data2: u10-u13
//data1: u6-u9
#if defined(ARDUINO_ARCH_RP2040)
#define PIN_DATA1 6 
#define PIN_DATA2 7
#define PIN_DATA3 8
#define PIN_DATA4 9

#define PIN_CLK 2
#define PIN_LATCH 3 
#define PIN_NOE 4
#elif defined(ESP8266)
#define PIN_DATA1 D6
#define PIN_DATA2 D2
#define PIN_DATA3 D1
#define PIN_DATA4 D8

#define PIN_CLK D7
#define PIN_LATCH D0
#define PIN_NOE D5
#endif
// TX = 0 
// RX = 1

#define PANELS_WIDTH 1
#define PANELS_HEIGHT 1

DMD3 display(PANELS_WIDTH, PANELS_HEIGHT);
char buf[100];

//Instead of Serial monitor, use mobaxterm/minicom
void clearSerialMonitor() 
{
  Serial.print("\033[2J\033[H\033[?25l");
}

void printCanvas()
{
  for (int i=0; i < 16 * PANELS_HEIGHT; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);    
  }
}

//top-left corner
void test1() 
{
  display.setPixel(0,0);
  printCanvas();
}

//top right corner
void test2() 
{
  display.setPixel(0,15);
  printCanvas();
}

//bottom right corner
void test3() 
{
  display.setPixel(15,15);
  printCanvas();
}

//bottom left corner
void test4() 
{
  display.setPixel(15,0);
  printCanvas();
}

void test5() 
{
  display.drawChar(0,0,'Q');
  printCanvas();
}

void test6()
{
  for (int i=48; i<=57; i++) {
   clearSerialMonitor();
   display.clear();
   display.drawChar(0,0,i);
   printCanvas();
   delay(600);
  }

  for (int i=65; i<=90; i++) {
   clearSerialMonitor();
   display.clear();
   display.drawChar(0,0,i);    
   printCanvas();
   delay(600);
  }

  for (int i=97; i<=122; i++) {
   clearSerialMonitor();
   display.clear();
   display.drawChar(0,0,i);    
    printCanvas();
    delay(600);
  }
  
}



void pixelScanGame()
{
  int width = 16 * PANELS_WIDTH;
  int height = 16 * PANELS_HEIGHT;
  
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

  
}

  

void setup()
{
  delay(1000);
  Serial.begin(115200);
  delay(5000);
    
  display.begin(PIN_CLK, PIN_LATCH, PIN_NOE, PIN_DATA1, PIN_DATA2, PIN_DATA3, PIN_DATA4);
  display.setBrightness(0.1);
  display.setFont(ArialFont16x16);

  //unsigned long timeStart = micros();
  //test1();
  //test2();
  //test3();
  //test4();
  //test5();
  test6();
  //pixelScanGame();
  

  
  
  //display.update();
 
  //unsigned long timeEnd = micros();
  //unsigned long duration = timeEnd - timeStart;
  //Serial.print("Duration(us):");
  //Serial.println(duration);
  
}



void loop()
{
 delay(5000);
}
