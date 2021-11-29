#pragma once

#include "command.h"
#include "games/dino/DinoImages.h"

class GameDino : public Command {
private:
  unsigned long timeStart = 0UL;
  char command;
  int objectTypeIndex;
  int objectIndex;
  int x;
  int y;
  bool dirty = false;

public:
  DMD3 *virtualCanvas;

  GameDino() { virtualCanvas = new DMD3(24, 2); }
  void parseArgs(std::vector<std::string> args) override {
    std::stringstream ss1, ss2, ss3, ss4, ss5;
    ss1 << args.at(0);
    ss1 >> command;
    ss2 << args.at(1);
    ss2 >> objectTypeIndex;
    ss3 << args.at(2);
    ss3 >> objectIndex;
    ss4 << args.at(3);
    ss4 >> x;
    ss5 << args.at(4);
    ss5 >> y;
    dirty = true;
  }

  void drawDinoGameObject(DMD3 *dmdObject) {
    int k = 0;
    int l = 0;

    uint8_t *data =
        (uint8_t *)DinoObjectTypes[objectTypeIndex][objectIndex].obj;
    int length = DinoObjectTypes[objectTypeIndex][objectIndex].length;
    int width = DinoObjectTypes[objectTypeIndex][objectIndex].width;

    int bytesPerRow = width / 8;

    for (int i = 0; i < length; i++) {

      uint8_t val = data[i];
      for (int j = 7; j >= 0; j--) {
        uint8_t pixel = (1 << j) & val;
        if (pixel != 0) {
          dmdObject->setPixel(7 - j + x + k, y + l);
        }
      }

      if (((i + 1) % bytesPerRow) == 0) {
        k = 0;
        l++;
      }

      else
        k = k + 8;
    }
  }

  void execute(DMD3 *canvas) override {
    if (dirty) {
      switch (command) {
      case 'd':
        drawDinoGameObject(virtualCanvas);
        break;

      case 'i':
        clearSerialMonitor();
        drawDinoGameObject(canvas);
        printCanvas(canvas);
        canvas->update();
        break;

      case 'u':
        clearSerialMonitor();
        virtualCanvas->copy(x, 0, 96, 32, canvas, 0, 0);
        printCanvas(canvas);
        canvas->update();
        break;
      }

      dirty = false;
    }
  }
};
