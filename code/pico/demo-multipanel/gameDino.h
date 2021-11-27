#pragma once

#include "command.h"
#include "games/dino/DinoImages.h"

class GameDino : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char command;
    int objectTypeIndex;
    int objectIndex;
    int x;
    int y;
    bool dirty = false;

  public:
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

    void drawCactus(DMD3 *canvas) {
      clearSerialMonitor();
      canvas->clear();


      for (int i = 0; i < SMALLCACTUS1_LENGTH; i++) {
        uint8_t val = SmallCactus1[i];
        for (int j = 7; j >= 0; j--) {
          uint8_t pixel = (1 << j) & val;
          if (pixel != 0) 
            canvas->setPixel(7 - j + x, i + y);
        }
      }

      printCanvas(canvas);
      canvas->update();

    }

    void drawDinosaur(DMD3 *canvas) {
            clearSerialMonitor();
      //canvas->clear();
      int k = 0;
      int l = 0;
      int bytesPerRow = DINOSTART_WIDTH / 8;

      for (int i = 0; i < DINOSTART_LENGTH; i++) {
        
        uint8_t val = DINOSTART[i];
        for (int j = 7; j >= 0; j--) {
          uint8_t pixel = (1 << j) & val;
          if (pixel != 0) {           
            canvas->setPixel(7 - j + x + k, y + l);
          }
        }

        if ( ((i + 1) % bytesPerRow) == 0) 
        {
          k= 0;  
          l++;
        }

        else 
           k = k + 8;
      }

      printCanvas(canvas);
      //canvas->update();
    }

    void drawDinoGameObject(DMD3 *canvas, int object_type_index, int object_index) {
       clearSerialMonitor();
       if (object_type_index == 0 && object_index == 0)
         canvas->clear();
      int k = 0;
      int l = 0;

      uint8_t *data = (uint8_t *) DinoObjectTypes[object_type_index][object_index].obj;
      int length = DinoObjectTypes[object_type_index][object_index].length;
      int width =  DinoObjectTypes[object_type_index][object_index].width;
      
      
      int bytesPerRow = width / 8;

      for (int i = 0; i < length; i++) {
        
        uint8_t val = data[i];
        for (int j = 7; j >= 0; j--) {
          uint8_t pixel = (1 << j) & val;
          if (pixel != 0) {           
            canvas->setPixel(7 - j + x + k, y + l);
          }
        }

        if ( ((i + 1) % bytesPerRow) == 0) 
        {
          k= 0;  
          l++;
        }

        else 
           k = k + 8;
      }

      printCanvas(canvas);
      canvas->update();
    }

    void execute(DMD3 *canvas)  override {
      if (dirty) {
        /*
        switch (command) {
         case 'B':  
        }
        */
        //drawCactus(canvas);
        //drawDinosaur(canvas);
        drawDinoGameObject(canvas,objectTypeIndex,objectIndex);
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
