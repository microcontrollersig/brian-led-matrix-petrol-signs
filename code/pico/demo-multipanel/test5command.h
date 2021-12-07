#pragma once
#include "testmode.h"

#include "command.h"


class Test5Command : public Command
{
  private:
    TestMovingMode mode = TestMovingMode::HORIZONTAL;
    int i = 0;
    int j = 0;
    unsigned long timeStart = 0UL;
    int panelX = 0;
    int panelY = 0;
    int panelXInitial = 0;
    int panelYInitial = 0;
    bool initialized = false;

  public:
    void execute(DMD3 *canvas)  override {
      if (!initialized) {
        int width = canvas->width();
        int height = canvas->height();
        panelX = width - 16;
        panelY = height - 16;
        panelXInitial = panelX;
        panelYInitial = panelY;
        initialized = true;
      }

      if ( millis() - timeStart > 3000) {
        clearSerialMonitor();
        canvas->clear();


        for (int i = 0; i < 16; i++) {
          for (int j = 0; j < 16; j++) {
            canvas->setPixel(panelX + i, panelY + j);
          }
        }


        panelX = panelX - 16;
        if (panelX == -16) {
          panelX = panelXInitial;
          panelY = panelY - 16;
          if (panelY == -16) {
            panelY = panelYInitial;
          }


        }

        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }

};
