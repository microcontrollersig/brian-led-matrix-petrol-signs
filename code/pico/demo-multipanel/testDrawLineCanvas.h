#pragma once

#include "command.h"

class TestDrawLineCanvasCommand : public Command
{
  private:
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    bool dirty = false;

  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1, ss2, ss3, ss4;
      ss1 << args.at(0);
      ss1 >> x1;
      ss2 << args.at(1);
      ss2 >> y1;
      ss3 << args.at(2);
      ss3 >> x2;
      ss4 << args.at(3);
      ss4 >> y2;
      dirty = true;
    }

    void execute(DMD3 *canvas)  override {
      if (dirty) {
        clearSerialMonitor();
        canvas->drawLine(x1, y1, x2, y2);
        printCanvas(canvas);
        canvas->update();
        dirty = false;
      }
    }
};
