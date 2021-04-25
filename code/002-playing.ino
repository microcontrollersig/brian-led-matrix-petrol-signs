#define PIN_DATA1 D7 //D2
#define PIN_CLK D5 

uint8_t clock_count = 0;

bool flag = false;

//uint16_t data = 0b1010101000111101;
uint16_t data = 0b1010101000000110; //datasheet SDI
uint16_t mask = 0x8000;

ICACHE_RAM_ATTR void pushData() {
  clock_count++;
  flag = true;
}

void setup() {
 pinMode(PIN_CLK, OUTPUT);
 pinMode(PIN_DATA1, OUTPUT);
 digitalWrite(PIN_CLK, LOW);
 digitalWrite(PIN_DATA1, LOW);
 delay(1000);
 //digitalWrite(PIN_DATA1, HIGH);
 digitalWrite(PIN_DATA1, (data & mask) ? HIGH: LOW);  
 mask = mask >> 1;
 delayMicroseconds(500);
 attachInterrupt(digitalPinToInterrupt(PIN_CLK), pushData, FALLING);
 analogWrite(PIN_CLK, 1023/2);

}

void loop() {
  if (flag) 
  {
    flag = false;
    
    if (clock_count == 16) {
        detachInterrupt(digitalPinToInterrupt(PIN_CLK)); 
        digitalWrite(PIN_CLK, LOW);
        digitalWrite(PIN_DATA1, LOW); 
        clock_count = 0;  
    }

    else {
      delayMicroseconds(250);
      digitalWrite(PIN_DATA1, (data & mask) ? HIGH: LOW);  
      mask = mask >> 1;
    }

  }

}
