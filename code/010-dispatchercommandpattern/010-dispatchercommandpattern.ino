#include "dispatcher.h"

Dispatcher *runner;

void setup() {
  Serial.begin(115200);
  delay(5000);
  /*
  std::vector<int> foo;
  for (int i=0; i<255; i++) {
    foo.push_back(i + 10);  
  }
  Serial.println(foo[10]);
  */
  
  runner = new Dispatcher();
  runner->dispatch('0');
}

void loop() {
  //runner->handleSerialInput();
  //runner->updatePanels();
  delay(5000);
}
