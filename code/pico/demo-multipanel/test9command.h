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
  
    int batsize = 8;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    int paddleOne = (32 - batsize)/2;
    int paddleTwo = (32 - batsize)/2;
    int speedX = 0;
    int speedY = 0;
        
  public:
    DMD3 *canvas;
    PongGameState gameState = PongGameState::INITIALIZE;
    int scoreboardCounter = 0;
    int ballX = 0;
    int ballY = 0;
    void setCanvas(DMD3 *c) { canvas = c; }
    void drawNet() {
      for (int i=0; i<16; i++) {
        canvas->setPixel(47, 2*i);
        canvas->setPixel(48, 2*i);
      }
    }
    void clearNet() {
      
    }
    void randomBall() {
      ballX = 48;
      ballY = random(16,31);
    }
    void drawBall() {
      canvas->setPixel(ballX, ballY);
    }
    void drawScore() {
      for (int i=0; i<15; i++) {
        if (rawNumberPixelData[playerOneScore % 10] & (1 << i)) {
          canvas->setPixel(41 + (i/5),0 + (i%5)); 
        }
      }

      for (int i=0; i<15; i++) {
        if (rawNumberPixelData[playerTwoScore % 10] & (1 << i)) {
          canvas->setPixel(52 + (i/5),0 + (i%5)); 
        }
      }      
    }
    void drawPaddles() {
      for (int i=0; i<batsize; i++) {
        canvas->setPixel(0, paddleOne + i);
      }

      for (int i=0; i<batsize; i++) {
        canvas->setPixel(95, paddleTwo + i);
      }
    }

    void startingPositions() {
      ballX = 48;
      ballY = random(16,31);
      speedX = 1;
      speedY = -1;
    }

    void resetGame() {
      playerOneScore = 0;
      playerTwoScore = 0;
      startingPositions();
    }




    
    bool moveBall() {
      ballX = ballX + speedX;
      ballY = ballY + speedY;

      if (ballX > 95) {
        playerOneScore++;
        return true;
      }
      
      else if (ballX < 0) {
        playerTwoScore++;
        return true;
      }

      if (ballY <= 0) {
        ballY = 0;
        speedY = -speedY;    
      } 
      
      else if (ballY >= 31) {
        ballY = 31;
        speedY = -speedY;  
      }  
      
      if (ballX == 95 && (ballY - paddleTwo >= 0 && ballY - paddleTwo <= batsize ) ) {
        speedX = -speedX;
      }

      if (ballX == 0 && (ballY - paddleTwo >= 0 && ballY - paddleTwo <= batsize ) ) {
        speedX = -speedX;
      }

      return false;
      
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
          uint16_t adc;

          if (pong.gameState == PongGameState::PLAYING && (pong.ballX > 95 | pong.ballX <0)) {
            pong.startingPositions();
            pong.gameState = PongGameState::SCOREUPDATE;
          }

          switch(pong.gameState) {
            case PongGameState::INITIALIZE:
              pong.setCanvas(canvas);
              pong.resetGame();
              pong.gameState = PongGameState::SCOREUPDATE;            
              adc_init();
              adc_set_temp_sensor_enabled(true);
              adc_select_input(4);
              adc = adc_read();
              randomSeed(adc);                  
              [[fallthrough]];

            case PongGameState::SCOREUPDATE:
               pong.drawNet();
               pong.drawPaddles();
               pong.drawScore();
               if (pong.scoreboardCounter++ > 40) {
                 pong.scoreboardCounter = 0; 
                 pong.gameState = PongGameState::PLAYING;
               }
               break;  

            case PongGameState::STARTGAME:
              pong.randomBall();
              pong.gameState = PongGameState::PLAYING;              
              break;

            case PongGameState::PLAYING:
               pong.moveBall();
               pong.drawBall();
               pong.drawPaddles();
               break;

                          
          }
          


          printCanvas(canvas);
          canvas->update();
          timeStart = millis();
       } 
    }
};
