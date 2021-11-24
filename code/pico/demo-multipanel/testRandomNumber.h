#pragma once

#include "command.h"
#include "randLIB.h"

class TestRandomNumberCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    unsigned long customTimeout = 0UL; 
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1;
      ss1 << args.at(0);
      ss1 >> customTimeout;
      randLIB_seed_random();
    }
  
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > customTimeout) {        
        clearSerialMonitor();
        canvas->clear();
        uint8_t num = randLIB_get_8bit();
        canvas->drawText(16,16, String(1 + (num % 100)));
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
