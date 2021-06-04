#pragma once

#include "command.h"
#include "testmode.h"
#include "snake.h"

class Test6Command : public Command
{
  private:
    Snake snake;
    DMD3 *_canvas;
    Position fruit;
    unsigned long timeStart = 0UL;
    TestDirectionMode currentDirection = TestDirectionMode::RIGHT;
    TestDirectionMode previousDirection = TestDirectionMode::RIGHT;
    bool gameEnded = true;
    
    void printSnakeBody() {
      //Serial.println("---");
      for (int i=0; i<snake.body_size; i++) {
       int x = snake.body[i].x;
       int y = snake.body[i].y;
       _canvas->setPixel(x,y);  
       //Serial.print("i:");
       //Serial.print(i);
       //Serial.print(" x:");
       //Serial.print(x);
       //Serial.print(" y:");
       //Serial.println(y);
      }
      //Serial.println("---");
    }

    void resetFruitPosition() {
      fruit.x = 14;
      fruit.y = 0;
    }

    void printFruit() {
      _canvas->setPixel(fruit.x, fruit.y);
    }
    
    /*
    void moveRight() {
      for (int i=0; i<snake.body_size; i++) {
        snake.body[i].x += 1;
        _canvas->setPixel(snake.body[i].x, snake.body[i].y);  
      }  

      
    }
    */

    void moveSnake(TestDirectionMode d) {
      for (int i=snake.body_size - 2; i >= 0; i--) {
        snake.body[i+1].x = snake.body[i].x;
        snake.body[i+1].y = snake.body[i].y;
      }  
      
      switch(d) {
        case TestDirectionMode::RIGHT :
        snake.body[0].y = snake.body[0].y;
        snake.body[0].x = snake.body[0].x + 1; 
        break;
      }           
    }

    bool isValidMove() {
    }

    void nextMove() {
      if (currentDirection == TestDirectionMode::RIGHT) {
        if (fruit.x >  snake.body[0].x) {
          moveSnake(TestDirectionMode::RIGHT);
        }

        else {
          if (fruit.y > snake.body[0].y) {
             moveSnake(TestDirectionMode::DOWN);
          }

          else if (fruit.y < snake.body[0].y ) {
              moveSnake(TestDirectionMode::UP);
          }
        }
      }
    }
  
  public:
    void execute(DMD3 *canvas)  override {

      if ( millis() - timeStart > 5000) {
        _canvas = canvas;
        clearSerialMonitor();
        canvas->clear();
        if (gameEnded) {
         gameEnded = false;
         resetFruitPosition();
         snake.resetBody();
        }
        else 
          nextMove();
        printSnakeBody();
        printFruit(); 
        int width = 16;
        int height = 16; 
        char buf[100];
        
        for (int z=0; z< height; z++) {
          canvas->debugPixelLine(z, buf);
          Serial.println(buf);    
        }
        
        timeStart = millis();
      }     
    }
};
