#pragma once

#include "command.h"

class TestCircleCanvasCommand : public Command
{
  private:
    int centerx = 0;
    int centery = 0;
    int radius = 0;
    int borderColor = 1;
    int fillColor = 1;
    bool dirty = false;

  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1, ss2, ss3, ss4, ss5;
      ss1 << args.at(0);
      ss1 >> centerx;
      ss2 << args.at(1);
      ss2 >> centery;
      ss3 << args.at(2);
      ss3 >> radius;
      ss4 << args.at(3);
      ss4 >> borderColor;
      ss5 << args.at(4);
      ss5 >> fillColor;
      dirty = true;
    }

    void execute(DMD3 *canvas)  override {
      if (dirty) {
        clearSerialMonitor();

        if (borderColor == 0 && fillColor == 0)
          canvas->drawCircle(centerx, centery, radius, Black, Black);
        if (borderColor == 0 && fillColor == 1)
          canvas->drawCircle(centerx, centery, radius, Black, White);
        if (borderColor == 1 && fillColor == 0)
          canvas->drawCircle(centerx, centery, radius, White, Black);
        if (borderColor == 1 && fillColor == 1)
          canvas->drawCircle(centerx, centery, radius, White, White);

        printCanvas(canvas);
        canvas->update();
        dirty = false;
      }
    }
};
