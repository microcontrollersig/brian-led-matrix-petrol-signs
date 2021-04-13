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


void setBrightness(uint8_t val) {

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
  
}

void loop() {

}
