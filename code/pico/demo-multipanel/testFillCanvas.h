#pragma once

#include "command.h"

class TestFillCanvasCommand : public Command
{
  private:
    int x = 0;
    int y = 0;
    int width = 1;
    int height = 1;
    bool dirty = false;
    int color;
  
  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1, ss2, ss3, ss4, ss5;
      ss1 << args.at(0);
      ss1 >> x;
      ss2 << args.at(1);
      ss2 >> y;     
      ss3 << args.at(2);
      ss3 >> width;
      ss4 << args.at(3);
      ss4 >> height;  
      ss5 << args.at(4);
      ss5 >> color; 
      dirty = true; 
    }
  
    void execute(DMD3 *canvas)  override {
      if (dirty) {
        clearSerialMonitor();
        if (color == 1)
          canvas->fill(x, y, width, height);
        else 
          canvas->fill(x, y, width, height, Black);
        printCanvas(canvas);
        canvas->update();    
        dirty = false;
      }
    }
};
