#pragma once

#include "command.h"

class Test3Command : public Command
{
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      canvas->clear();
      canvas->setPixel(15,0);
      printCanvas(canvas); 
      canvas->update();
    }
};
