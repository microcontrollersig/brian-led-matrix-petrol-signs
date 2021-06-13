#include "MBI5039.h"

#define CLOCK_PERIOD_USECS 20 //digitalWrites add time, for 20us adds about 30us

#if defined(ESP8266)
#define MAX_PWM_VALUE 1023
#else
#define MAX_PWM_VALUE 255
#endif



void MBI5039::setBrightness(float b)
{
  brightness = (int) ((1.0 - b) * MAX_PWM_VALUE);
}

void MBI5039::disable()
{
  digitalWrite(noe_pin, HIGH);
}

void MBI5039::enable()
{
  analogWrite(noe_pin, brightness);
}

void MBI5039::latch()
{
  delayMicroseconds(250);
  digitalWrite(latch_pin, HIGH);
  delayMicroseconds(250);
  digitalWrite(latch_pin, LOW);
  delayMicroseconds(250);
}



void MBI5039::sendData(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, bool bitOrder) 
{
  uint8_t mask;
  if (bitOrder) 
    mask = 0x80;
  else
    mask = 1;

  //Serial.println("What...");

  for (int i=0; i<8; i++)
  {
    
    sendOneBit(data1, data2, data3, data4, mask);

    if (bitOrder)
      mask = mask >> 1;
    else
      mask = mask << 1;

    digitalWrite(clock_pin, LOW);
    delayMicroseconds(CLOCK_PERIOD_USECS);
    digitalWrite(clock_pin, HIGH);
    delayMicroseconds(CLOCK_PERIOD_USECS);
    digitalWrite(clock_pin, LOW);
  }

  digitalWrite(data1_pin, LOW);
  digitalWrite(data2_pin, LOW);
  digitalWrite(data3_pin, LOW);
  digitalWrite(data4_pin, LOW);
}



void MBI5039::sendOneBit(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t mask)
{
  digitalWrite(data1_pin, (data1 & mask) ? HIGH:LOW);
  digitalWrite(data2_pin, (data2 & mask) ? HIGH:LOW);
  digitalWrite(data3_pin, (data3 & mask) ? HIGH:LOW);
  digitalWrite(data4_pin, (data4 & mask) ? HIGH:LOW);  
}
