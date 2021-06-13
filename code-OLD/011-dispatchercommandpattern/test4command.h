#pragma once

#include "command.h"

class Test4Command : public Command
{
  public:
    void execute()  override {
      clearSerialMonitor();
      Serial.println("Running Test4...");  
    }
};
