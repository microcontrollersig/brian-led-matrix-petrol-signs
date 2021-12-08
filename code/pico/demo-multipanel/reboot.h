#pragma once

#include "mbed_power_mgmt.h"
#include "command.h"

class RebootCommand : public Command
{
  public:
    void execute(DMD3 *canvas)  override {
      system_reset();
    }
};
