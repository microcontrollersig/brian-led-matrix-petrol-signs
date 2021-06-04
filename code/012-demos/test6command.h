#pragma once

#include "command.h"
#include "testmode.h"
#include "snake.h"

class Test6Command : public Command
{
  private:
    Snake snake;
    DMD3 *_canvas;
    void printSnakeBody() {
      for (int i=0; i<snake.body_size; i++) {
       int x = snake.body[i].x;
       int y = snake.body[i].y;
       _canvas->setPixel(x,y);  
      }
    }
    
    void resetSnake() {
      snake.resetBody();
      printSnakeBody();
    }
  
  public:
    void execute(DMD3 *canvas)  override {
      _canvas = canvas;
      clearSerialMonitor();
      canvas->clear();
      resetSnake(); 
      int width = 16;
      int height = 16; 
      char buf[100];
      for (int z=0; z< height; z++) {
         canvas->debugPixelLine(z, buf);
         Serial.println(buf);    
      }      
    }
};
