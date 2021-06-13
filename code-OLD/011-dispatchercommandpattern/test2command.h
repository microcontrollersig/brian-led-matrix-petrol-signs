#pragma once

#include "command.h"

class Test2Command : public Command
{
  public:
    void execute()  override {
      clearSerialMonitor();
      Serial.println("Running Test2...");  
    }
};
