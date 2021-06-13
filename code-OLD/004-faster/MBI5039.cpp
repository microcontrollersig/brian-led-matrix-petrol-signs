#include "MBI5039.h"

void MBI5039::sendData(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4) 
{
  uint16_t mask = 0x8000;

  for (int i=0; i<16; i++) {
    sendOneBit(data1, data2, data3, data4, mask);
    mask = mask >> 1;
    digitalWrite(clock_pin, HIGH);
    digitalWrite(clock_pin, LOW);
  }

}


void MBI5039::sendOneBit(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4, uint16_t mask)
{
  digitalWrite(data1_pin, (data1 & mask) ? HIGH:LOW);
  digitalWrite(data2_pin, (data2 & mask) ? HIGH:LOW);
  digitalWrite(data3_pin, (data3 & mask) ? HIGH:LOW);
  digitalWrite(data4_pin, (data4 & mask) ? HIGH:LOW);
}
