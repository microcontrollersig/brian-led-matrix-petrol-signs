#include "MBI5039.h"

#define PIN_DATA1 D2
#define PIN_DATA2 D1
#define PIN_DATA3 D6
#define PIN_DATA4 D8
#define PIN_CLK D7
#define PIN_LATCH D0
#define PIN_NOE D5

#define DATA_SEGMENTS_PER_PANEL 4

MBI5039 p3(PIN_CLK, PIN_LATCH, PIN_NOE, PIN_DATA1, PIN_DATA2, PIN_DATA3, PIN_DATA4);

void setup() {
  pinMode(PIN_CLK, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_NOE, OUTPUT);
  pinMode(PIN_DATA1, OUTPUT);
  pinMode(PIN_DATA2, OUTPUT);
  pinMode(PIN_DATA3, OUTPUT);
  pinMode(PIN_DATA4, OUTPUT);
  
  digitalWrite(PIN_NOE, HIGH);
  digitalWrite(PIN_CLK, LOW);
  digitalWrite(PIN_LATCH, LOW);
  digitalWrite(PIN_DATA1, LOW);
  digitalWrite(PIN_DATA2, LOW);
  digitalWrite(PIN_DATA3, LOW);
  digitalWrite(PIN_DATA4, LOW);

  delay(1000);

  //0b0000000000000000
  //0b1111111111111111
  //0b1010101010101010
  //0b1110000000000101
  //0b0000000000000100
  //0b0000001100000000
  uint16_t data1 = 0b1010101010101010;
  uint16_t data2 = 0b1010101010101010;
  uint16_t data3 = 0b1010101010101010;
  uint16_t data4 = 0b1010101010101010;

  for (int i=0; i<DATA_SEGMENTS_PER_PANEL; i++)
  {
    p3.sendData(data1, data2, data3, data4);
    delayMicroseconds(1);
  }

  /*
    p3.sendData(0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111100000000, false);
    p3.sendData(0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111111111111, false);
    p3.sendData(0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111111111111, false);
    p3.sendData(0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111111111111, false);   
   */

  digitalWrite(PIN_LATCH, HIGH);
  digitalWrite(PIN_LATCH, LOW);
  digitalWrite(PIN_NOE, LOW);
  digitalWrite(PIN_NOE, HIGH);
}

void loop() {
  

}
