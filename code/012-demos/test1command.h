#pragma once

#include "command.h"

class Test1Command : public Command
{
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      canvas->clear();
      canvas->setPixel(0,0);
      printCanvas(canvas);
    }
};
