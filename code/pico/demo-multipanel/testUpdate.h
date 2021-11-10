#pragma once

#include "command.h"

class TestUpdateCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    bool dirty = false;
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      dirty = true;
    }
      
    void execute(DMD3 *canvas)  override {
      if ( dirty ) {        
        clearSerialMonitor();
        printCanvas(canvas);
        canvas->update();
        dirty = false;
      }
    }
};
