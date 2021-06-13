#include "dispatcher.h"

Dispatcher *runner;

void setup() {
  Serial.begin(115200);
  delay(5000);
  
  runner = new Dispatcher();
  //runner->dispatch('0');
}

void loop() {
  runner->handleSerialInput();
  //delay(5000);
}
