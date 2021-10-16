#pragma once

#include "command.h"

class TestSetPixelCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    bool dirty = false;
    int x;
    int y;
    bool pixel;
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss, ss1, ss2;
      ss << args.at(0);
      ss >> x;  
      ss1 << args.at(1);
      ss1 >> y;
      ss2 << args.at(2);
      ss2 >> pixel;  
      dirty = true;                  
    }
  
    void execute(DMD3 *canvas)  override {
      if (dirty) {
        clearSerialMonitor();
        if (pixel)
          canvas->setPixel(x, y);
        else
          canvas->clearPixel(x, y);
        printCanvas(canvas);
        canvas->update();
        dirty = false;   
      }
    }
};
