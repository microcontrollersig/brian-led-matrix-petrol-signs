
#include "dispatcher.h"
#include "DMD3.h"
#include "customglcdfonts.h"

#if defined(ARDUINO_ARCH_RP2040)
#define PIN_DATA1 3 
#define PIN_DATA2 4
#define PIN_DATA3 5
#define PIN_DATA4 2

#define PIN_CLK 12
#define PIN_LATCH 11 
#define PIN_NOE 10
#elif defined(ESP8266)
#define PIN_DATA1 D6
#define PIN_DATA2 D2
#define PIN_DATA3 D1
#define PIN_DATA4 D8

#define PIN_CLK D7
#define PIN_LATCH D0
#define PIN_NOE D5
#endif
// TX = 0 
// RX = 1

#define PANELS_WIDTH 1
#define PANELS_HEIGHT 1

DMD3 display(PANELS_WIDTH, PANELS_HEIGHT);

Dispatcher *runner;

void setup() {
  Serial.begin(115200);
  delay(5000);

  display.begin(PIN_CLK, PIN_LATCH, PIN_NOE, PIN_DATA1, PIN_DATA2, PIN_DATA3, PIN_DATA4);
  display.setBrightness(0.1);
  display.setFont(ArialFont16x16);
  
  runner = new Dispatcher(&display);
  runner->dispatch('@');
}

void loop() {
  runner->handleSerialInput();
  //delay(5000);
}
