#include "MBI5039.h"

#if defined(ESP8266)
#define MAX_PWM_VALUE 1023
#else
#define MAX_PWM_VALUE 255
#endif

#define CLOCK_PERIOD_USECS 50
#define HALF_CLOCK_PERIOD CLOCK_PERIOD_USECS/2

void MBI5039::myAnalogWrite(pin_size_t pin, int val)
{
  /*
    int write_resolution = 8;
    mbed::PwmOut* pwm = new mbed::PwmOut(digitalPinToPinName(pin));
    //pwm->period_ms(2); //500Hz
    pwm->period_us(100); //100kHz
    float percent = (float)val/(float)((1 << write_resolution)-1);
    pwm->write(percent);
    */
}

void MBI5039::setBrightness(uint8_t b)
{
  brightness = b;
}

uint8_t MBI5039::getBrightness()
{
  return brightness;
}

void MBI5039::disable()
{
  digitalWrite(noe_pin, HIGH);
}

void MBI5039::enable()
{
  //analogWrite(noe_pin, 254);
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
   sendData(data1, data2, data3, data4, true);    
}

void MBI5039::sendDataLSB(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4)
{
   sendData(data1, data2, data3, data4, false);
}

void MBI5039::sendData(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4, bool bitOrder) 
{
  uint8_t mask;
  if (bitOrder) 
    mask = 0x80;
  else
    mask = 1;


  for (int i=0; i<8; i++)
  {
    
    sendOneBit(*data1, *data2, *data3, *data4, mask);

    if (bitOrder)
      mask = mask >> 1;
    else
      mask = mask << 1;

    digitalWrite(clock_pin, LOW);
    //delayMicroseconds(HALF_CLOCK_PERIOD);
    digitalWrite(clock_pin, HIGH);
    //delayMicroseconds(HALF_CLOCK_PERIOD);
    digitalWrite(clock_pin, LOW);
  }

  digitalWrite(data1_pin, LOW);
  digitalWrite(data2_pin, LOW);
  digitalWrite(data3_pin, LOW);
  digitalWrite(data4_pin, LOW);
}

void MBI5039::sendData(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4, bool bitOrder) 
{

}

void MBI5039::sendOneBit(uint8_t data1, uint8_t data2, uint8_t data3, uint8_t data4, uint8_t mask)
{
  digitalWrite(data1_pin, (data1 & mask) ? HIGH:LOW);
  digitalWrite(data2_pin, (data2 & mask) ? HIGH:LOW);
  digitalWrite(data3_pin, (data3 & mask) ? HIGH:LOW);
  digitalWrite(data4_pin, (data4 & mask) ? HIGH:LOW);  
}

void MBI5039::sendOneBit(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4, uint16_t mask)
{
  digitalWrite(data1_pin, (data1 & mask) ? HIGH:LOW);
  digitalWrite(data2_pin, (data2 & mask) ? HIGH:LOW);
  digitalWrite(data3_pin, (data3 & mask) ? HIGH:LOW);
  digitalWrite(data4_pin, (data4 & mask) ? HIGH:LOW);
}

/*
void MBI5039::myAnalogWrite(pin_size_t pin, int val) 
{
    mbed::PwmOut* pwm = new mbed::PwmOut(digitalPinToPinName(pin));
    //pwm->period_ms(2); //500Hz
    pwm->period_us(10); //100kHz
    float percent = val/255.0;
    pwm->write(percent);
}
*/
