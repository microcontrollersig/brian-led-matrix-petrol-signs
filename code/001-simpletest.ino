#define PIN_OE 11
#define PIN_LATCH 12 // sometimes called strobe pin
#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5
#define PIN_CLK 6
#define PIN_R1 7
#define PIN_R2 8
#define PIN_G1 9
#define PIN_G2 10

uint16_t row = 0;

void setBrightness(uint8_t val) {
  analogWrite(PIN_OE, val);
}

void cycle() {

  digitalWrite(PIN_A, (row & 0b1000) >> 3);
  digitalWrite(PIN_B, (row & 0b0100) >> 2);
  digitalWrite(PIN_C, (row & 0b0010) >> 1);
  digitalWrite(PIN_D,  row & 0b0001);

  row = (row + 1) % 16;
}

void setup() {
  pinMode(PIN_OE, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_CLK, OUTPUT);
  pinMode(PIN_R1, OUTPUT);
  pinMode(PIN_R2, OUTPUT);
  pinMode(PIN_G1, OUTPUT);
  pinMode(PIN_G2, OUTPUT);

  setBrightness(255/2);
  
  digitalWrite(PIN_LAT, LOW);
  for (int i=0; i<4; i++) {
    shiftOut(PIN_R1, PIN_CLK, MSBFIRST, 0b10101010);
    shiftOut(PIN_R1, PIN_CLK, MSBFIRST, 0b10101010);  
  }
  digitalWrite(PIN_LAT, HIGH);
  digitalWrite(PIN_LAT, LOW);
  
  delay(5000);
  

}

void loop() {
  cycle();
  delay(3000);
}
