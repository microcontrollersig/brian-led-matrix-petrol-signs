#pragma once

#include "command.h"

class Test1Command : public Command
{
  public:
    void execute()  override {
      clearSerialMonitor();
      Serial.println("Running Test1...");  
    }
};
