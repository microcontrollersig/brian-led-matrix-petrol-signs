#pragma once

#include "command.h"

class Test7Command : public Command
{
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      Serial.println("Running Test7...");  
    }
};
