#pragma once

#include "command.h"

class Test8Command : public Command
{
  public:
    void execute()  override {
      clearSerialMonitor();
      Serial.println("Running Test8...");  
    }
};
