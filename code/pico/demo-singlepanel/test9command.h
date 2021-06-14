#pragma once

#include "command.h"

const int rawNumberPixelData[] = {32319, 31744, 24253, 32437, 31879, 30391, 30399, 31777, 32447, 32439};

enum class PongGameState {
  INITIALIZE,
  STARTGAME,
  PLAYING,
  SCOREUPDATE
};

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
    PongGameState gameState = PongGameState::INITIALIZE;
    int scoreboardCounter = 0;
    void setCanvas(DMD3 *c) { canvas = c; }
    void drawNet() {
      for (int i=0; i<8; i++) {
        canvas->setPixel(7, 2*i);
        canvas->setPixel(8, 2*i);
      }
    }
    void clearNet() {
      
    }
    void randomBall() {
      ballX = 8;
      ballY = random(0,15);
    }
    void drawBall() {
      canvas->setPixel(ballX, ballY);
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
       if ( millis() - timeStart > 1000) {
          clearSerialMonitor();
          canvas->clear();

          switch(pong.gameState) {
            case PongGameState::INITIALIZE:
              pong.setCanvas(canvas);
              pong.drawNet();
              pong.drawPaddles();
              pong.drawScore();
              if (pong.scoreboardCounter > 5) {
                pong.gameState = PongGameState::STARTGAME;
                pong.scoreboardCounter = 0;                
                adc_init();
                adc_set_temp_sensor_enabled(true);
                adc_select_input(4);
                uint16_t adc = adc_read();
                randomSeed(adc);                  
              }
              else 
                pong.scoreboardCounter++;              
              break;

            case PongGameState::STARTGAME:
              pong.randomBall();
              pong.gameState = PongGameState::PLAYING;

            case PongGameState::PLAYING:
               pong.drawBall();
               pong.drawPaddles();
               break;

            case PongGameState::SCOREUPDATE:
               pong.drawNet();
               pong.drawPaddles();
               pong.drawScore();
               break;                            
          }
          


          printCanvas(canvas);
          //canvas->update();
          timeStart = millis();
       } 
    }
};
