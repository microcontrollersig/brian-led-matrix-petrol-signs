#pragma once

#include "command.h"

class TestScrollOneLineCommand : public Command {
private:
  unsigned long timeStart = 0UL;
  char text2[500];
  int fontIndex = 0;
  int x = 0;
  int y = 0;

  int panelWidthPixels;
  int panelHeightPixels; 

  int currentScrollX = 0;
  int scrollTextSize = 0;

  int counter = 0;
  bool scrollingMode = false;
  int timeOutMs = 60;

  int yoffset = 0;

  bool dirty = false;

public:
  DMD3 *scrollingCanvas;

  TestScrollOneLineCommand() {
    scrollingCanvas = new DMD3(50, 1);
    scrollingCanvas->setFont(VerdanaFont16x16);
    scrollingCanvas->clear();

    
  }

  void parseArgs(std::vector<std::string> args) override {
    std::stringstream ss1, ss2;

    memset(text2, ' ', sizeof(text2));
    strcpy(text2, args.at(0).c_str());
    ss2 << args.at(1);
    ss2 >> yoffset;
    ss1 << args.at(2);
    ss1 >> fontIndex;
    dirty = true;
    scrollingCanvas->clear();
    currentScrollX = 0;
  }

  void execute(DMD3 *canvas) override {
    if (dirty) {
      panelWidthPixels = canvas->width();
      panelHeightPixels = canvas->height();
      
      switch (fontIndex) {
      case 0:
        scrollingCanvas->drawText(panelWidthPixels, 0, text2);
        scrollTextSize = 16 * strlen(text2) + 106;
        break;

      case 1:
        Bitmap::Font defaultFont = scrollingCanvas->font();
        scrollingCanvas->setFont(fonts[fontIndex]);
        scrollingCanvas->drawText(panelWidthPixels, 0, text2, true);
        scrollingCanvas->setFont(defaultFont);
        scrollTextSize = 7 * strlen(text2) + 106;
        break;
      }
      dirty = false;
    }

    if (millis() - timeStart > 40) {
      clearSerialMonitor();
      canvas->clear();

      if (fontIndex == 0)
        scrollingCanvas->copy(currentScrollX, 0, panelWidthPixels, 16, canvas, 0, yoffset);
      else 
        scrollingCanvas->copy(currentScrollX, 0, panelWidthPixels, panelHeightPixels/2, canvas, 0, yoffset);

      printCanvas(canvas);
      canvas->update();
      if (currentScrollX++ > scrollTextSize) {
        currentScrollX = 0;
      }
      timeStart = millis();
    }
  }
};
