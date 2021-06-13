// esp8266 lolin v3
// esp8266 safe pins https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
#define PIN_DATA1 4 //D2
#define PIN_DATA2 5 //D1
#define PIN_DATA3 9 //S2
#define PIN_DATA4 10 //S3

#define PIN_NOE 12  //D7
#define PIN_LATCH 13 // D6- sometimes called strobe pin
#define PIN_CLK 14 //D5

#define SEGMENTS_PER_PANEL 8

//#define DEBUG

void fourChannelShiftOut(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4) 
{  
  uint16_t mask = 0x8000;
  
  for (uint16_t i = 0; i <16 ; i++)  
  {
    digitalWrite(PIN_DATA1, (data1 & mask)?HIGH:LOW);
    digitalWrite(PIN_DATA2, (data2 & mask)?HIGH:LOW);
    digitalWrite(PIN_DATA3, (data3 & mask)?HIGH:LOW);
    digitalWrite(PIN_DATA4, (data4 & mask)?HIGH:LOW);    
    #ifdef DEBUG
      Serial.println((data1 & mask)?HIGH:LOW);
      Serial.println((data2 & mask)?HIGH:LOW);
      Serial.println((data3 & mask)?HIGH:LOW);
      Serial.println((data4 & mask)?HIGH:LOW);
      delay(5000);
    #endif
    mask = mask >> 1;
    digitalWrite(PIN_CLK, HIGH);
    delayMicroseconds(1);
    digitalWrite(PIN_CLK, LOW);
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_DATA1, OUTPUT);
  pinMode(PIN_DATA2, OUTPUT);
  pinMode(PIN_DATA3, OUTPUT);
  pinMode(PIN_DATA4, OUTPUT);
  
  pinMode(PIN_CLK, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_NOE, OUTPUT);
  
  digitalWrite(PIN_NOE, HIGH);
 
  
  uint16_t data1 = 0b1010101010101010;
  uint16_t data2 = 0b1110011111100111;
  uint16_t data3 = 0b0000000000000000;
  uint16_t data4 = 0b1111111111111111;

  for (int i=0; i < SEGMENTS_PER_PANEL; i++) 
  {
    fourChannelShiftOut(data1, data2, data3, data4);  
  }
  
  digitalWrite(PIN_LATCH, HIGH);
  delayMicroseconds(1);
  digitalWrite(PIN_LATCH, LOW);
  analogWrite(PIN_NOE, 1023/2);
}

void loop()
{

}
