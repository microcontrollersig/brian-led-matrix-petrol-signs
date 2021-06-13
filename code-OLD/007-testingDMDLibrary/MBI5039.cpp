#include "MBI5039.h"

void IRAM_ATTR MBI5039::isr() 
{
  fallingClockEdge = true;
  clockCount++;
}

void MBI5039::setBrightness(float b)
{
  brightness = (int) ((1.0 - b) * 1023);
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

void MBI5039::sendDataMSB(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4)
{
    clockCount = 0;
    uint16_t mask = 0x80;

    sendOneBit(data1, data2, data3, data4, mask);
    attachInterrupt(clock_pin, std::bind(&MBI5039::isr, this), FALLING);  
    analogWrite(clock_pin, 1023/2);

    while(true) 
    {
      if (fallingClockEdge) 
      {
        fallingClockEdge = false;

        if (clockCount == 8) 
        {
          clockCount = 0;
          detachInterrupt(clock_pin);
          digitalWrite(clock_pin, LOW);

          digitalWrite(data1_pin, LOW);
          digitalWrite(data2_pin, LOW);
          digitalWrite(data3_pin, LOW);
          digitalWrite(data4_pin, LOW);
          break;
        }

        else 
        {
          delayMicroseconds(200);
          mask = mask >> 1;
          sendOneBit(data1, data2, data3, data4, mask);
        }
      }
    }    

    
}

void MBI5039::sendDataLSB(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4)
{
    clockCount = 0;
    uint16_t mask = 1;

    sendOneBit(data1, data2, data3, data4, mask);
    attachInterrupt(clock_pin, std::bind(&MBI5039::isr, this), FALLING);  
    analogWrite(clock_pin, 1023/2);

    while(true) 
    {
      if (fallingClockEdge) 
      {
        fallingClockEdge = false;

        if (clockCount == 8) 
        {
          clockCount = 0;
          detachInterrupt(clock_pin);
          digitalWrite(clock_pin, LOW);

          digitalWrite(data1_pin, LOW);
          digitalWrite(data2_pin, LOW);
          digitalWrite(data3_pin, LOW);
          digitalWrite(data4_pin, LOW);
          break;
        }

        else 
        {
          delayMicroseconds(200);
          mask = mask << 1;
          sendOneBit(data1, data2, data3, data4, mask);
        }
      }
    }      
}

void MBI5039::sendData(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4, bool bitOrder) 
{
  clockCount = 0;
  uint16_t mask;
  if (bitOrder) 
    mask = 1;
  else
    mask = 0x8000;

  sendOneBit(data1, data2, data3, data4, mask);
  attachInterrupt(clock_pin, std::bind(&MBI5039::isr, this), FALLING);  
  analogWrite(clock_pin, 1023/2);


  while(true) 
  {
    if (fallingClockEdge) 
    {
      fallingClockEdge = false;

      if (clockCount == 16) 
      {
        clockCount = 0;
        detachInterrupt(clock_pin);
        digitalWrite(clock_pin, LOW);

        digitalWrite(data1_pin, LOW);
        digitalWrite(data2_pin, LOW);
        digitalWrite(data3_pin, LOW);
        digitalWrite(data4_pin, LOW);
        break;
      }

      else 
      {
        delayMicroseconds(200);
        if (bitOrder)
          mask = mask << 1;
        else
          mask = mask >> 1;
        sendOneBit(data1, data2, data3, data4, mask);

      }
    }
  }

}

void MBI5039::sendOneBit(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4, uint16_t mask)
{
  digitalWrite(data1_pin, (*data1 & mask) ? HIGH:LOW);
  digitalWrite(data2_pin, (*data2 & mask) ? HIGH:LOW);
  digitalWrite(data3_pin, (*data3 & mask) ? HIGH:LOW);
  digitalWrite(data4_pin, (*data4 & mask) ? HIGH:LOW);  
}

void MBI5039::sendOneBit(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4, uint16_t mask)
{
  digitalWrite(data1_pin, (data1 & mask) ? HIGH:LOW);
  digitalWrite(data2_pin, (data2 & mask) ? HIGH:LOW);
  digitalWrite(data3_pin, (data3 & mask) ? HIGH:LOW);
  digitalWrite(data4_pin, (data4 & mask) ? HIGH:LOW);
}
