#pragma once

#include "command.h"

class TestTwoLinesTextCanvasCommand : public Command
{
  private:
    char text1[100];
    char text2[100];
    int fontIndex = 0;
    int xTop = 0;
    int yTop = 0;
    int xBottom = 0;
    int yBottom = 0;
    bool dirty = false;

  public:
    void parseArgs(std::vector<std::string> args) override {
      std::stringstream ss1, ss2, ss3, ss4, ss5;
      ss1 << args.at(0);
      ss1 >> xTop;
      ss2 << args.at(1);
      ss2 >> yTop;
      strcpy(text1, args.at(2).c_str());
      ss3 << args.at(3);
      ss3 >> xBottom;
      ss4 << args.at(4);
      ss4 >> yBottom;
      strcpy(text2, args.at(5).c_str());
      ss5 << args.at(6);
      ss5 >> fontIndex;
      dirty = true;
    }

    void execute(DMD3 *canvas)  override {
      if (dirty) {
        clearSerialMonitor();
        switch(fontIndex) {
          case 0:
            canvas->drawText(xTop,yTop, text1); 
            canvas->drawText(xBottom,yBottom, text2); 
            break;

          default:
            Bitmap::Font defaultFont = canvas->font();
            canvas->setFont(fonts[fontIndex]);
            canvas->drawText(xTop,yTop, text1);
            canvas->drawText(xBottom,yBottom, text2);
            canvas->setFont(defaultFont);              
            break;
        }
        printCanvas(canvas);
        canvas->update();
        dirty = false;
      }
    }
};
