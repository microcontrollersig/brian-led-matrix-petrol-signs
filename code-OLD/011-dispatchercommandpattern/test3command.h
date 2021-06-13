#pragma once

#include "command.h"

class Test3Command : public Command
{
  public:
    void execute()  override {
      clearSerialMonitor();
      Serial.println("Running Test3...");  
    }
};
