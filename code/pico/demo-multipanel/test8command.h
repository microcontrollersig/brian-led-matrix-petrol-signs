#pragma once

#include "command.h"

class Test8Command : public Command
{  
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      canvas->clear();
      printCanvas(canvas);
      canvas->update();
    }
};
