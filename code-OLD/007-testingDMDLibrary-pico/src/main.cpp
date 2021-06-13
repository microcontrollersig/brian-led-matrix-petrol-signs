#include <Arduino.h>

//#pragma once

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
#define PIN_DATA1 6 
#define PIN_DATA2 7
#define PIN_DATA3 8
#define PIN_DATA4 9

#define PIN_CLK 2
#define PIN_LATCH 3 
#define PIN_NOE 4

// TX = 0 
// RX = 1

#define PANELS_WIDTH 1
#define PANELS_HEIGHT 1

DMD3 display(PANELS_WIDTH, PANELS_HEIGHT);

//top-left corner
void test1() 
{
  display.setPixel(0,0,DMD3::White);
}

//top right corner
void test2() 
{
  display.setPixel(0,15,DMD3::White);
}

//bottom right corner
void test3() 
{
  display.setPixel(15,15,DMD3::White);
}

//bottom left corner
void test4() 
{
  display.setPixel(15,0,DMD3::White);
}

void test5() 
{
  display.drawChar(0,0,'Q');
}

void setup()
{
  Serial.begin(9600);
  delay(10000);
  char buf[100];
  
  display.begin(PIN_CLK, PIN_LATCH, PIN_NOE, PIN_DATA1, PIN_DATA2, PIN_DATA3, PIN_DATA4);
  display.setBrightness(0.1);
  display.setFont(ArialFont16x16);

  //unsigned long timeStart = micros();
  //test1();
  //test2();
  //test3();
  //test4();
  test5();
  
  
  for (int i=0; i<16; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
    delay(100);
  }
  
  
  display.update();
  
  //unsigned long timeEnd = micros();
  //unsigned long duration = timeEnd - timeStart;
  //Serial.print("Duration(us):");
  //Serial.println(duration);
  
}



void loop()
{

}

/*
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
*/
