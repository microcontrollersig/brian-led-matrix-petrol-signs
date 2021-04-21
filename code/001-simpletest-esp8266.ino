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

#define DEBUG 


void fourChannelShiftOut(uint16_t data1, uint16_t data2, uint16_t data3, uint16_t data4) 
{  
    uint16_t mask = 0x8000;
  
	for (uint16_t i = 15; i >=3 ; i--)  {
      digitalWrite(PIN_DATA1, (data & mask));
    
        PORTC = (PORTC & 0xf0) |  (data1 & mask) >> i | (data2 & mask) >> (i-1) | (data3 & mask) >> (i-2) | (data4 & mask) >> (i-3);
        mask = mask >> 1;
		digitalWrite(PIN_CLK, HIGH);
		digitalWrite(PIN_CLK, LOW);
        #ifdef DEBUG
        Serial.print("0b");
        Serial.println(PORTC, BIN);
        delay(5000);
        #endif
	}
  
    PORTC = (PORTC & 0xf0) |  (data1 & mask) >> 2 | (data2 & mask) >> 1 | (data3 & mask) | (data4 & mask) << 1;
  	digitalWrite(PIN_CLK, HIGH);
	digitalWrite(PIN_CLK, LOW);		
    #ifdef DEBUG
          Serial.print("0b");
        Serial.println(PORTC, BIN);
        delay(5000);
    #endif
    mask = mask >> 1;
    PORTC = (PORTC & 0xf0) |  (data1 & mask) >> 1 | (data2 & mask)  | (data3 & mask) << 1 | (data4 & mask) << 2;
    digitalWrite(PIN_CLK, HIGH);
	digitalWrite(PIN_CLK, LOW);		
    #ifdef DEBUG
          Serial.print("0b");
        Serial.println(PORTC, BIN);
        delay(5000);
    #endif
    mask = mask >> 1;
    PORTC = (PORTC & 0xf0) | (data1 & mask) | (data2 & mask) << 1 | (data3 & mask) << 2 | (data4 & mask) << 3;
  	digitalWrite(PIN_CLK, HIGH);
	digitalWrite(PIN_CLK, LOW);    
    #ifdef DEBUG
          Serial.print("0b");
        Serial.println(PORTC, BIN);
        delay(5000);
    #endif
}


void setup()
{
  Serial.begin(9600);

  //sets analog pins(A0-A3) as output
  DDRC |= 0x0f;
  
  pinMode(PIN_CLK, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  //pinMode(PIN_NOE, OUTPUT);
  
  analogWrite(PIN_NOE, 255);
 
  
  uint16_t data1 = 0b1010101010101010;
  uint16_t data2 = 0b1110011111100111;
  uint16_t data3 = 0b0000000000000000;
  uint16_t data4 = 0b1111111111111111;

  for (int i=0; i < SEGMENTS_PER_PANEL; i++) {
    fourChannelShiftOut(data1, data2, data3, data4);  
  }
  
  digitalWrite(PIN_LATCH, HIGH);
  digitalWrite(PIN_LATCH, LOW);
  analogWrite(PIN_NOE, 255/2);


}

void loop()
{

}
