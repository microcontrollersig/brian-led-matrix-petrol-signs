#pragma once

#include "command.h"

class TestIdleCommand : public Command
{
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      canvas->clear();
      printCanvas(canvas);
      canvas->update();
    }
};
