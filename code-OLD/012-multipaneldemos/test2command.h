#pragma once

#include "command.h"

class Test2Command : public Command
{
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      Serial.println("Running Test2...");  
    }
};
