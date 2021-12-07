#pragma once

#include "command.h"

class Test2Command : public Command
{
  private:
    unsigned long timeStart = 0UL;

  public:
    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 2000) {
        int width = canvas->width();
        int height = canvas->height();
        int topRightCorner_x = width - 1;
        int bottomLeftCorner_y = height - 1;
        clearSerialMonitor();
        canvas->clear();
        canvas->setPixel(0, 0);
        canvas->setPixel(topRightCorner_x, 0);
        canvas->setPixel(0, bottomLeftCorner_y);
        canvas->setPixel(topRightCorner_x, bottomLeftCorner_y);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
