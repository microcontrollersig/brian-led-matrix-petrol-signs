#pragma once

#include "command.h"
#include "games/dino/SmallCactus1.h"

class GameDino : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char command;
    int x;
    int y;
    bool dirty = false;

  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1, ss2, ss3;
      ss1 << args.at(0);
      ss1 >> command;
      ss2 << args.at(1);
      ss2 >> x;
      ss3 << args.at(2);
      ss3 >> y;
      dirty = true;
    }

    void drawCactus(DMD3 *canvas) {
      clearSerialMonitor();
      canvas->clear();


      for (int i = 0; i < SMALLCACTUS1_LENGTH; i++) {
        uint8_t val = SmallCactus1[i];
        for (int j = 7; j >= 0; j--) {
          uint8_t pixel = (1 << j) & val;
          if (pixel != 0) 
            canvas->setPixel(7 - j, i);
        }
      }

      printCanvas(canvas);
      canvas->update();

    }

    void execute(DMD3 *canvas)  override {
      if (dirty) {
        drawCactus(canvas);
        dirty = false;
      }
      /*
        if ( millis() - timeStart > 1000) {
        clearSerialMonitor();
        printCanvas(canvas);

        timeStart = millis();
        }
      */
    }
};
