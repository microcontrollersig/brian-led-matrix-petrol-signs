#pragma once

#define SNAKE_SIZE 6

class Position
{
  public:
    int x = 0;
    int y = 0;
    Position() {}
    Position(int _x, int _y) : x(_x),y(_y) {}  
};

class Snake {
  public:
    Position body[SNAKE_SIZE];
    Snake() {
      resetBody();
    }
    int body_size = SNAKE_SIZE;
    void resetBody() {
      for (int i=0; i<SNAKE_SIZE; i++) {
        body[i] = Position(i,0);
      }       
    }
};
