#pragma once

#include "command.h"

class Test1Command : public Command
{
  public:
    void execute(DMD3 *canvas)  override {
      clearSerialMonitor();
      canvas->clear();
      canvas->drawText(0,0, "Tell a");
      canvas->drawText(0,16, " Joke");
      printCanvas(canvas);
      //canvas->update();
    }
};
