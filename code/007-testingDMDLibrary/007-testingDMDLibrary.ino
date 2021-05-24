#pragma once

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
#define PIN_DATA1 D6
#define PIN_DATA2 D2
#define PIN_DATA3 D1
#define PIN_DATA4 D8

#define PIN_CLK D7
#define PIN_LATCH D0
#define PIN_NOE D5

int brightness;

void setPanelBrightness(float b) 
{
 brightness = (int) ((1.0 - b) * 255);
}

void panelsON()
{
  analogWrite(PIN_NOE, brightness);
}

DMD3 display(1,1);

void setup()
{
  Serial.begin(115200);
  delay(2000);
  char buf[100];
  display.setPins(PIN_CLK, PIN_LATCH, PIN_NOE, PIN_DATA1, PIN_DATA2, PIN_DATA3, PIN_DATA4);
  display.setFont(ArialFont16x16);
  //display.setPixel(0,0,DMD3::White);
  //display.setPixel(0,15,DMD3::White);
  //display.setPixel(15,15,DMD3::White);
  //display.setPixel(15,0,DMD3::White);
  display.drawChar(0,0,'Q');
  
  for (int i=0; i<16; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
  }
  
  display.update();
  
}



void loop()
{

}
