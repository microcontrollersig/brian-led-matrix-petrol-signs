#pragma once

#include "command.h"

const int rawNumberPixelData[] = {32319, 31744, 24253, 32437, 31879, 30391, 30399, 31777, 32447, 32439};

class Pong
{
  private:
    int batsize = 4;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    int ballX = 0;
    int ballY = 0;
    int paddleX = (16 - batsize)/2;
    int paddleY = (16 - batsize)/2;

    
  public:
    DMD3 *canvas;
    void setCanvas(DMD3 *c) { canvas = c; }
    void drawNet() {
      for (int i=0; i<8; i++) {
        canvas->setPixel(7, 2*i);
        canvas->setPixel(8, 2*i);
      }
    }
    void clearNet() {
      
    }
    void drawBall() {
    }
    void drawScore() {
      for (int i=0; i<15; i++) {
        if (rawNumberPixelData[playerOneScore % 10] & (1 << i)) {
          canvas->setPixel(2 + (i/5),0 + (i%5)); 
        }
      }

      for (int i=0; i<15; i++) {
        if (rawNumberPixelData[playerTwoScore % 10] & (1 << i)) {
          canvas->setPixel(11 + (i/5),0 + (i%5)); 
        }
      }      
    }
    void drawPaddles() {
      for (int i=0; i<batsize; i++) {
        canvas->setPixel(0, paddleX + i);
      }

      for (int i=0; i<batsize; i++) {
        canvas->setPixel(15, paddleY + i);
      }
    }
    void resetGame() {
      playerOneScore = 0;
      playerTwoScore = 0;
      ballX = 0;
      ballY = 0;
    }
};

class Test9Command : public Command
{
  private:
    unsigned long timeStart = 0UL;
    Pong pong;
  
  public:
    void execute(DMD3 *canvas)  override {
       if ( millis() - timeStart > 100) {
          clearSerialMonitor();
          canvas->clear();
          if (pong.canvas == NULL) {
            pong.setCanvas(canvas);
          }

          pong.drawBall();
          pong.drawNet();
          pong.drawPaddles();
          pong.drawScore();

          printCanvas(canvas);
          //canvas->update();
       } 
    }
};
