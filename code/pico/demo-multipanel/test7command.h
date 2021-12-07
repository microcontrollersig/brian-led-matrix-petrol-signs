#pragma once

#include "command.h"
#include "testmode.h"
#include "snake.h"

class Test7Command : public Command
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
      for (int i = 0; i < snake.body_size; i++) {
        int x = snake.body[i].x;
        int y = snake.body[i].y;
        _canvas->setPixel(x, y);
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
      for (int i = snake.body_size - 2; i >= 0; i--) {
        snake.body[i + 1].x = snake.body[i].x;
        snake.body[i + 1].y = snake.body[i].y;
      }

      switch (d) {
        case TestDirectionMode::RIGHT :
          snake.body[0].y = snake.body[0].y;
          snake.body[0].x = snake.body[0].x + 1;
          break;
        case TestDirectionMode::DOWN :
          snake.body[0].x = snake.body[0].x;
          snake.body[0].y = snake.body[0].y + 1;
          break;
        case TestDirectionMode::LEFT :
          snake.body[0].y = snake.body[0].y;
          snake.body[0].x = snake.body[0].x - 1;
          break;
        case TestDirectionMode::UP :
          snake.body[0].x = snake.body[0].x;
          snake.body[0].y = snake.body[0].y - 1;
          break;
      }

      currentDirection = d;
    }

    bool isValidMove() {
    }

    void moveHorizontal() {
      if (fruit.x > snake.body[0].x)
        moveSnake(TestDirectionMode::RIGHT);
      else if (fruit.x < snake.body[0].x )
        moveSnake(TestDirectionMode::LEFT);
      else {
        if (snake.body[0].y < 8)
          moveSnake(TestDirectionMode::DOWN);
        else
          moveSnake(TestDirectionMode::UP);
      }
    }

    void moveVertical() {
      if (fruit.y > snake.body[0].y)
        moveSnake(TestDirectionMode::DOWN);
      else if (fruit.y < snake.body[0].y )
        moveSnake(TestDirectionMode::UP);
      else {
        if (snake.body[0].x < 8)
          moveSnake(TestDirectionMode::RIGHT);
        else
          moveSnake(TestDirectionMode::LEFT);
      }
    }

    void nextMove() {
      if (currentDirection == TestDirectionMode::RIGHT) {
        if (fruit.x >  snake.body[0].x)
          moveSnake(TestDirectionMode::RIGHT);
        else
          moveVertical();
      }

      else if (currentDirection == TestDirectionMode::DOWN) {
        if (fruit.y > snake.body[0].y)
          moveSnake(TestDirectionMode::DOWN);
        else
          moveHorizontal();
      }

      else if (currentDirection == TestDirectionMode::LEFT) {
        if (fruit.x < snake.body[0].x)
          moveSnake(TestDirectionMode::LEFT);
        else
          moveVertical();
      }

      else if (currentDirection == TestDirectionMode::UP) {
        if (fruit.y < snake.body[0].y)
          moveSnake(TestDirectionMode::UP);
        else
          moveHorizontal();
      }
    }

    bool hasGameEnded() {
      return false;
    }

    bool hasSnakeEatenFruit() {
      return (snake.body[0].x == fruit.x) && (snake.body[0].y == fruit.y);
    }

    bool isPositionOnSnakeBody(int pos_x, int pos_y) {
      for (int i = 0; i < snake.body_size; i++) {
        Position p = snake.body[i];
        if (p.x == pos_x && p.y == pos_y)
          return true;
      }
      return false;
    }

    void randomFruitPosition(int w, int h) {

      int random_x = random(0, w);
      int random_y = random(0, h);
      if (!isPositionOnSnakeBody(random_x, random_y)) {
        fruit.x = random_x;
        fruit.y = random_y;
      }
      else
        randomFruitPosition(w, h);
    }

  public:
    void execute(DMD3 *canvas)  override {

      if ( millis() - timeStart > 100) {
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
        /*
          int width = 96;
          int height = 32;
          char buf[100];


          for (int z=0; z< height; z++) {
          canvas->debugPixelLine(z, buf);
          Serial.println(buf);
          }
        */
        printCanvas(canvas);

        if (hasGameEnded()) {
          gameEnded = true;
        }

        if (hasSnakeEatenFruit()) {
          int width = canvas->width();
          int height = canvas->height();
          randomFruitPosition(width - 1 , height - 1);
        }

        canvas->update();
        timeStart = millis();
      }
    }
};
