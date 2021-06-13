#pragma once

#include "command.h"

class Test7Command : public Command
{
  public:
    void execute()  override {
      clearSerialMonitor();
      Serial.println("Running Test7...");  
    }
};
