#pragma once

#include "command.h"

class Test6Command : public Command
{
  public:
    void execute()  override {
      clearSerialMonitor();
      Serial.println("Running Test6...");  
    }
};
