#pragma once
#include <Arduino.h>
#include <FunctionalInterrupt.h>

class MBI5039
{
  public:
    MBI5039(uint8_t clock_pin, uint8_t latch_pin, uint8_t noe_pin, uint8_t data1_pin, uint8_t data2_pin, uint8_t data3_pin, uint8_t data4_pin) : 
                clock_pin(clock_pin), latch_pin(latch_pin), noe_pin(noe_pin), 
                data1_pin(data1_pin), data2_pin(data2_pin), data3_pin(data3_pin), data4_pin(data4_pin)
                {
                }
    void IRAM_ATTR isr();
    void sendData(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4, bool bitOrder);
    void sendDataMSB(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4);
    void sendDataLSB(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4)  ;
    void sendOneBit(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4, uint16_t mask);
    void sendOneBit(uint8_t *data1, uint8_t *data2, uint8_t *data3, uint8_t *data4, uint16_t mask);
  private:
    uint8_t clock_pin, 
            latch_pin,
            noe_pin,
            data1_pin,
            data2_pin,
            data3_pin,
            data4_pin;
     volatile uint8_t clockCount;
     volatile bool fallingClockEdge;
};
