#pragma once
#include "MBI5039.h"
#include "DMDv3.h"

#define PIN_DATA1 D2
#define PIN_DATA2 D1
#define PIN_DATA3 D6
#define PIN_DATA4 D8
#define PIN_CLK D7
#define PIN_LATCH D0
#define PIN_NOE D5

//#define DATA_SEGMENTS_PER_PANEL 4

MBI5039 p3(PIN_CLK, PIN_LATCH, PIN_NOE, PIN_DATA1, PIN_DATA2, PIN_DATA3, PIN_DATA4);

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
  display.setMBI5039(&p3);
  display.setFont(ArialFont16x16);
  //for (int j=0; j<10; j++)
  //display.setPixel(00,0,DMD3::White);
  display.drawChar(0,0,'Q');
  
  //display.drawChar(80,0,'E' ); //#=35 , "=34
  
  /*
  for (int i=0; i<8; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
    
  }
  */
  
  /*
  for (int i=8; i<16; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
    
  }
  */
  
    /*
  for (int i=16; i<24; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
    
  }
  */
  
    /*
  for (int i=24; i<32; i++) {
    display.debugPixelLine(i, buf);
    Serial.println(buf);
    
  }
  */
  
  //display.getD1BankData(1);
  //display.refreshData();
  
  for (int i=0; i<16; i++) {
        display.debugPixelLine(i, buf);
    Serial.println(buf);
  }
  
  display.update();
  
}



void loop()
{

}
