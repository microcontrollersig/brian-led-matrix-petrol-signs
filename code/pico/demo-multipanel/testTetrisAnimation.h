#pragma once

#define TETRIS_MAX_NUMBERS 9
#define TETRIS_DISTANCE_BETWEEN_DIGITS 7
#define TETRIS_Y_DROP_DEFAULT 16
#define SIZE_NUM_0 12

#include "command.h"

typedef struct
{
  int blocktype;  // Number of the block type
  int color; // Color of the brick
  int x_pos;      // x-position (starting from the left number staring point) where the brick should be placed
  int y_stop;     // y-position (1-16, where 16 is the last line of the matrix) where the brick should stop falling
  int num_rot;    // Number of 90-degree (clockwise) rotations a brick is turned from the standard position
} fall_instr;

const int xShiftClock[4] = {0, 7, 17, 24};


static const fall_instr num_0[SIZE_NUM_0] = {
  {2, 5, 4, 16, 0},
  {4, 7, 2, 16, 1},
  {3, 4, 0, 16, 1},
  {6, 6, 1, 16, 1},
  {5, 1, 4, 14, 0},
  {6, 6, 0, 13, 3},
  {5, 1, 4, 12, 0},
  {5, 1, 0, 11, 0},
  {6, 6, 4, 10, 1},
  {6, 6, 0, 9, 1},
  {5, 1, 1, 8, 1},
  {2, 5, 3, 8, 3}
};

// *********************************************************************
// Number 1
// *********************************************************************
#define SIZE_NUM_1 5
static const fall_instr num_1[SIZE_NUM_1] = {
  {2, 5, 4, 16, 0},
  {3, 4, 4, 15, 1},
  {3, 4, 5, 13, 3},
  {2, 5, 4, 11, 2},
  {0, 0, 4, 8, 0}
};

// *********************************************************************
// Number 2
// *********************************************************************
#define SIZE_NUM_2 11
static const fall_instr num_2[SIZE_NUM_2] = {
  {0, 0, 4, 16, 0},
  {3, 4, 0, 16, 1},
  {1, 2, 1, 16, 3},
  {1, 2, 1, 15, 0},
  {3, 4, 1, 12, 2},
  {1, 2, 0, 12, 1},
  {2, 5, 3, 12, 3},
  {0, 0, 4, 10, 0},
  {3, 4, 1, 8, 0},
  {2, 5, 3, 8, 3},
  {1, 2, 0, 8, 1}
};

// *********************************************************************
// Number 3
// *********************************************************************
#define SIZE_NUM_3 11
static const fall_instr num_3[SIZE_NUM_3] = {
  {1, 2, 3, 16, 3},
  {2, 5, 0, 16, 1},
  {3, 4, 1, 15, 2},
  {0, 0, 4, 14, 0},
  {3, 4, 1, 12, 2},
  {1, 2, 0, 12, 1},
  {3, 4, 5, 12, 3},
  {2, 5, 3, 11, 0},
  {3, 4, 1, 8, 0},
  {1, 2, 0, 8, 1},
  {2, 5, 3, 8, 3}
};

// *********************************************************************
// Number 4
// *********************************************************************
#define SIZE_NUM_4 9
static const fall_instr num_4[SIZE_NUM_4] = {
  {0, 0, 4, 16, 0},
  {0, 0, 4, 14, 0},
  {3, 4, 1, 12, 0},
  {1, 2, 0, 12, 1},
  {2, 5, 0, 10, 0},
  {2, 5, 3, 12, 3},
  {3, 4, 4, 10, 3},
  {2, 5, 0, 9, 2},
  {3, 4, 5, 10, 1}
};

// *********************************************************************
// Number 5
// *********************************************************************
#define SIZE_NUM_5 11
static const fall_instr num_5[SIZE_NUM_5] = {
  {0, 0, 0, 16, 0},
  {2, 5, 2, 16, 1},
  {2, 5, 3, 15, 0},
  {3, 4, 5, 16, 1},
  {3, 4, 1, 12, 0},
  {1, 2, 0, 12, 1},
  {2, 5, 3, 12, 3},
  {0, 0, 0, 10, 0},
  {3, 4, 1, 8, 2},
  {1, 2, 0, 8, 1},
  {2, 5, 3, 8, 3}
};

// *********************************************************************
// Number 6
// *********************************************************************
#define SIZE_NUM_6 12
static const fall_instr num_6[SIZE_NUM_6] = {
  {2, 5, 0, 16, 1},
  {5, 1, 2, 16, 1},
  {6, 6, 0, 15, 3},
  {6, 6, 4, 16, 3},
  {5, 1, 4, 14, 0},
  {3, 4, 1, 12, 2},
  {2, 5, 0, 13, 2},
  {3, 4, 2, 11, 0},
  {0, 0, 0, 10, 0},
  {3, 4, 1, 8, 0},
  {1, 2, 0, 8, 1},
  {2, 5, 3, 8, 3}
};

// *********************************************************************
// Number 7
// *********************************************************************
#define SIZE_NUM_7 7
static const fall_instr num_7[SIZE_NUM_7] = {
  {0, 0, 4, 16, 0},
  {1, 2, 4, 14, 0},
  {3, 4, 5, 13, 1},
  {2, 5, 4, 11, 2},
  {3, 4, 1, 8, 2},
  {2, 5, 3, 8, 3},
  {1, 2, 0, 8, 1}
};

// *********************************************************************
// Number 8
// *********************************************************************
#define SIZE_NUM_8 13
static const fall_instr num_8[SIZE_NUM_8] = {
  {3, 4, 1, 16, 0},
  {6, 6, 0, 16, 1},
  {3, 4, 5, 16, 1},
  {1, 2, 2, 15, 3},
  {4, 7, 0, 14, 0},
  {1, 2, 1, 12, 3},
  {6, 6, 4, 13, 1},
  {2, 5, 0, 11, 1},
  {4, 7, 0, 10, 0},
  {4, 7, 4, 11, 0},
  {5, 1, 0, 8, 1},
  {5, 1, 2, 8, 1},
  {1, 2, 4, 9, 2}
};

// *********************************************************************
// Number 9
// *********************************************************************
#define SIZE_NUM_9 12
static const fall_instr num_9[SIZE_NUM_9] = {
  {0, 0, 0, 16, 0},
  {3, 4, 2, 16, 0},
  {1, 2, 2, 15, 3},
  {1, 2, 4, 15, 2},
  {3, 4, 1, 12, 2},
  {3, 4, 5, 12, 3},
  {5, 1, 0, 12, 0},
  {1, 2, 2, 11, 3},
  {5, 1, 4, 9, 0},
  {6, 6, 0, 10, 1},
  {5, 1, 0, 8, 1},
  {6, 6, 2, 8, 2}
};

static const int blocksPerNumber[10] = {SIZE_NUM_0, SIZE_NUM_1, SIZE_NUM_2, SIZE_NUM_3, SIZE_NUM_4, SIZE_NUM_5, SIZE_NUM_6, SIZE_NUM_7, SIZE_NUM_8, SIZE_NUM_9};

// *********************************************************************
// Helper function that that return the falling instruction for a given number
// *********************************************************************
static const fall_instr getFallinstrByNum(int num, int blockindex)
{
  if (num == 0)
  {
    return num_0[blockindex];
  }
  if (num == 1)
  {
    return num_1[blockindex];
  }
  if (num == 2)
  {
    return num_2[blockindex];
  }
  if (num == 3)
  {
    return num_3[blockindex];
  }
  if (num == 4)
  {
    return num_4[blockindex];
  }
  if (num == 5)
  {
    return num_5[blockindex];
  }
  if (num == 6)
  {
    return num_6[blockindex];
  }
  if (num == 7)
  {
    return num_7[blockindex];
  }
  if (num == 8)
  {
    return num_8[blockindex];
  }

  // implicit return
  return num_9[blockindex];
}



// Type that describes the current state of a drawn number
typedef struct
{
  int num_to_draw; // Number to draw (0-9)
  int blockindex;  // The index of the brick (as defined in the falling instructions) that is currently falling
  int fallindex;   // y-position of the brick it already has (incrementing with each step)
  int x_shift;     // x-position of the number relative to the matrix where the number should be placed.
} numstate;


class GenericDisplay {
  private:
   DMD3* cvs;
  
  public:
    GenericDisplay(DMD3 *canvas) {
      this->cvs = canvas;  
    }
    void fillRect(int x1, int y1, int width, int height, uint16_t color) {
      cvs->fill(x1, y1, width, height);
    }
    
    void drawPixel(int x, int y, uint16_t color) {
      cvs->setPixel(x,y);
    }
};



class TetrisMatrixDraw
{
  public:
    GenericDisplay *display;
    bool initialisedDisplay = false;

    TetrisMatrixDraw() {
       
    }

    void setDisplay(DMD3* canvas) {
      if (!initialisedDisplay) {
        display =  new GenericDisplay(canvas);
        initialisedDisplay = true;
      }
    }
    
    /*
    TetrisMatrixDraw (GenericDisplay *display) {
      this->display = display;
    }
    */


    bool drawNumbers(int x = 0, int yFinish = 0, bool displayColon = false) {
      // For each number position
      bool finishedAnimating = true;

      int scaledYOffset = (this->scale > 1) ? this->scale : 1;
      int y = yFinish - (TETRIS_Y_DROP_DEFAULT * this->scale);

      for (int numpos = 0; numpos < this->sizeOfValue; numpos++)
      {
        if (numstates[numpos].num_to_draw >= 0)
        {
          // Draw falling shape
          if (numstates[numpos].blockindex < blocksPerNumber[numstates[numpos].num_to_draw])
          {
            finishedAnimating = false;
            fall_instr current_fall = getFallinstrByNum(numstates[numpos].num_to_draw, numstates[numpos].blockindex);

            // Handle variations of rotations
            uint8_t rotations = current_fall.num_rot;
            if (rotations == 1)
            {
              if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 2))
              {
                rotations = 0;
              }
            }
            if (rotations == 2)
            {
              if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 3))
              {
                rotations = 0;
              }
              if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 3 * 2))
              {
                rotations = 1;
              }
            }
            if (rotations == 3)
            {
              if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 4))
              {
                rotations = 0;
              }
              if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 4 * 2))
              {
                rotations = 1;
              }
              if (numstates[numpos].fallindex < (int)(current_fall.y_stop / 4 * 3))
              {
                rotations = 2;
              }
            }

            if (this->scale <= 1) {
              drawShape(current_fall.blocktype,
                        this->tetrisColors[current_fall.color],
                        x + current_fall.x_pos + numstates[numpos].x_shift,
                        y + numstates[numpos].fallindex - scaledYOffset,
                        rotations);
            } else {
              drawLargerShape(this->scale,
                              current_fall.blocktype,
                              this->tetrisColors[current_fall.color],
                              x + (current_fall.x_pos * this->scale) + numstates[numpos].x_shift,
                              y + (numstates[numpos].fallindex * scaledYOffset) - scaledYOffset,
                              rotations);
            }
            numstates[numpos].fallindex++;

            if (numstates[numpos].fallindex > current_fall.y_stop)
            {
              numstates[numpos].fallindex = 0;
              numstates[numpos].blockindex++;
            }
          }

          // Draw already dropped shapes
          if (numstates[numpos].blockindex > 0)
          {
            for (int i = 0; i < numstates[numpos].blockindex; i++)
            {
              fall_instr fallen_block = getFallinstrByNum(numstates[numpos].num_to_draw, i);
              if (this->scale <= 1) {
                drawShape(fallen_block.blocktype,
                          this->tetrisColors[fallen_block.color],
                          x + fallen_block.x_pos + numstates[numpos].x_shift,
                          y + fallen_block.y_stop - 1,
                          fallen_block.num_rot);
              } else {
                drawLargerShape(this->scale,
                                fallen_block.blocktype,
                                this->tetrisColors[fallen_block.color],
                                x + (fallen_block.x_pos * this->scale) + numstates[numpos].x_shift,
                                y + (fallen_block.y_stop * scaledYOffset) - scaledYOffset,
                                fallen_block.num_rot);
              }
            }
          }
        }
      }

      if (displayColon)
      {
        this->drawColon(x, y, this->tetrisWHITE);
      }

      return finishedAnimating;
    }
    bool drawText(int x = 0, int y = 0);
    void drawChar(String letter, uint8_t x, uint8_t y, uint16_t color = 1);
    void drawShape(int blocktype, uint16_t color, int x_pos, int y_pos, int num_rot) {
      // Square
      if (blocktype == 0)
      {
        this->display->drawPixel(x_pos, y_pos, color);
        this->display->drawPixel(x_pos + 1, y_pos, color);
        this->display->drawPixel(x_pos, y_pos - 1, color);
        this->display->drawPixel(x_pos + 1, y_pos - 1, color);
      }

      // L-Shape
      if (blocktype == 1)
      {
        if (num_rot == 0)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos, y_pos - 2, color);
        }
        if (num_rot == 1)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 2, y_pos - 1, color);
        }
        if (num_rot == 2)
        {
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 2, color);
          this->display->drawPixel(x_pos, y_pos - 2, color);
        }
        if (num_rot == 3)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 2, y_pos, color);
          this->display->drawPixel(x_pos + 2, y_pos - 1, color);
        }
      }

      // L-Shape (reverse)
      if (blocktype == 2)
      {
        if (num_rot == 0)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 2, color);
        }
        if (num_rot == 1)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 2, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
        }
        if (num_rot == 2)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos, y_pos - 2, color);
          this->display->drawPixel(x_pos + 1, y_pos - 2, color);
        }
        if (num_rot == 3)
        {
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 2, y_pos - 1, color);
          this->display->drawPixel(x_pos + 2, y_pos, color);
        }
      }

      // I-Shape
      if (blocktype == 3)
      {
        if (num_rot == 0 || num_rot == 2)
        { // Horizontal
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 2, y_pos, color);
          this->display->drawPixel(x_pos + 3, y_pos, color);
        }
        if (num_rot == 1 || num_rot == 3)
        { // Vertical
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos, y_pos - 2, color);
          this->display->drawPixel(x_pos, y_pos - 3, color);
        }
      }

      // S-Shape
      if (blocktype == 4)
      {
        if (num_rot == 0 || num_rot == 2)
        {
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos, y_pos - 2, color);
        }
        if (num_rot == 1 || num_rot == 3)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 2, y_pos - 1, color);
        }
      }

      // S-Shape (reversed)
      if (blocktype == 5)
      {
        if (num_rot == 0 || num_rot == 2)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 2, color);
        }
        if (num_rot == 1 || num_rot == 3)
        {
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 2, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
        }
      }

      // Half cross
      if (blocktype == 6)
      {
        if (num_rot == 0)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos + 2, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
        }
        if (num_rot == 1)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos, y_pos - 2, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
        }
        if (num_rot == 2)
        {
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 2, y_pos - 1, color);
        }
        if (num_rot == 3)
        {
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 2, color);
        }
      }

      // Corner-Shape
      if (blocktype == 7)
      {
        if (num_rot == 0)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
        }
        if (num_rot == 1)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
        }
        if (num_rot == 2)
        {
          this->display->drawPixel(x_pos + 1 , y_pos, color);
          this->display->drawPixel(x_pos + 1 , y_pos - 1, color);
          this->display->drawPixel(x_pos, y_pos - 1, color);
        }
        if (num_rot == 3)
        {
          this->display->drawPixel(x_pos, y_pos, color);
          this->display->drawPixel(x_pos + 1, y_pos , color);
          this->display->drawPixel(x_pos + 1, y_pos - 1, color);
        }
      }

    }
    void drawLargerShape(int scale, int blocktype, uint16_t color, int x_pos, int y_pos, int num_rot) {
      int offset1 = 1 * scale;
      int offset2 = 2 * scale;
      int offset3 = 3 * scale;

      // Square
      if (blocktype == 0)
      {
        this->drawLargerBlock(x_pos, y_pos, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
        this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
        return;
      }

      // L-Shape
      if (blocktype == 1)
      {
        if (num_rot == 0)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset2, scale, color);
          return;
        }
        if (num_rot == 1)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos - offset1, scale, color);
          return;
        }
        if (num_rot == 2)
        {
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset2, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset2, scale, color);
          return;
        }
        if (num_rot == 3)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos - offset1, scale, color);
          return;
        }
      }

      // L-Shape (reverse)
      if (blocktype == 2)
      {
        if (num_rot == 0)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset2, scale, color);
          return;
        }
        if (num_rot == 1)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          return;
        }
        if (num_rot == 2)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset2, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset2, scale, color);
          return;
        }
        if (num_rot == 3)
        {
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos, scale, color);
          return;
        }
      }

      // I-Shape
      if (blocktype == 3)
      {
        if (num_rot == 0 || num_rot == 2)
        { // Horizontal
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset3, y_pos, scale, color);
          return;
        }
        //if (num_rot == 1 || num_rot == 3)
        //{ // Vertical
        this->drawLargerBlock(x_pos, y_pos, scale, color);
        this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
        this->drawLargerBlock(x_pos, y_pos - offset2, scale, color);
        this->drawLargerBlock(x_pos, y_pos - offset3, scale, color);
        return;
        //}
      }

      // S-Shape
      if (blocktype == 4)
      {
        if (num_rot == 0 || num_rot == 2)
        {
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset2, scale, color);
          return;
        }
        //if (num_rot == 1 || num_rot == 3)
        //{
        this->drawLargerBlock(x_pos, y_pos, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
        this->drawLargerBlock(x_pos + offset2, y_pos - offset1, scale, color);
        return;
        //}
      }

      // S-Shape (reversed)
      if (blocktype == 5)
      {
        if (num_rot == 0 || num_rot == 2)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset2, scale, color);
          return;
        }
        //if (num_rot == 1 || num_rot == 3)
        //{
        this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
        this->drawLargerBlock(x_pos + offset2, y_pos, scale, color);
        this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
        return;
        //}
      }

      // Half cross
      if (blocktype == 6)
      {
        if (num_rot == 0)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          return;
        }
        if (num_rot == 1)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset2, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          return;
        }
        if (num_rot == 2)
        {
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset2, y_pos - offset1, scale, color);
          return;
        }
        //if (num_rot == 3)
        //{
        this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
        this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos - offset2, scale, color);
        //}
      }

      // Corner-Shape
      if (blocktype == 7)
      {
        if (num_rot == 0)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          return;
        }
        if (num_rot == 1)
        {
          this->drawLargerBlock(x_pos, y_pos, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
          return;
        }
        if (num_rot == 2)
        {
          this->drawLargerBlock(x_pos + offset1 , y_pos, scale, color);
          this->drawLargerBlock(x_pos + offset1 , y_pos - offset1, scale, color);
          this->drawLargerBlock(x_pos, y_pos - offset1, scale, color);
          return;
        }
        //if (num_rot == 3)
        //{
        this->drawLargerBlock(x_pos, y_pos, scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos , scale, color);
        this->drawLargerBlock(x_pos + offset1, y_pos - offset1, scale, color);
        //}
      }
    }
    void setTime(String time, bool forceRefresh = false) {
      this->sizeOfValue = 4;
      time.replace(":", "");
      for (uint8_t pos = 0; pos < 4; pos++)
      {
        int xOffset = pos * TETRIS_DISTANCE_BETWEEN_DIGITS * this->scale;
        if (pos >= 2) {
          xOffset += (3 * this->scale);
        }
        String individualNumber = time.substring(pos, pos + 1);
        int number = (individualNumber != " ") ? individualNumber.toInt() : -1;
        // Only change the number if its different or being forced
        if (forceRefresh || number != this->numstates[pos].num_to_draw)
        {
          setNumState(pos, number, xOffset);
        }
      }
    }
    void setNumbers(int value, bool forceRefresh = false) {
      String strValue = String(value);
      if (strValue.length() <= TETRIS_MAX_NUMBERS) {
        this->sizeOfValue = strValue.length();
        int currentXShift = 0;
        for (uint8_t pos = 0; pos < this->sizeOfValue; pos++)
        {
          currentXShift = TETRIS_DISTANCE_BETWEEN_DIGITS * this->scale * pos;
          int number = strValue.substring(pos, pos + 1).toInt();
          // Only change the number if its different or being forced
          if (forceRefresh || number != this->numstates[pos].num_to_draw)
          {
            setNumState(pos, number, currentXShift);
          } else {
            this->numstates[pos].x_shift = currentXShift;
          }
        }
      } else {
        Serial.println("Number too long");
      }
    }
    void setText(String txt, bool forceRefresh = false) {
      this->sizeOfValue = txt.length();
      int currentXShift = 0;
      for (uint8_t pos = 0; pos < this->sizeOfValue; pos++)
      {
        currentXShift = TETRIS_DISTANCE_BETWEEN_DIGITS * this->scale * pos;
        char letter = txt.charAt(pos);
        if (forceRefresh || (int)letter != this->numstates[pos].num_to_draw)
        {
          setNumState(pos, (int)letter, currentXShift);
        } else {
          this->numstates[pos].x_shift = currentXShift;
        }
      }
    }

    void setNumState(int index, int value, int x_shift) {
      if (index < TETRIS_MAX_NUMBERS) {
        Serial.println(value);
        this->numstates[index].num_to_draw = value;
        this->numstates[index].x_shift = x_shift;
        this->numstates[index].fallindex = 0;
        this->numstates[index].blockindex = 0;
      }
    }
    void drawColon(int x, int y, uint16_t colonColour = 1) {
      int colonSize = 2 * this->scale;
      int xColonPos = x + (TETRIS_DISTANCE_BETWEEN_DIGITS * 2 * this->scale);
      display->fillRect(xColonPos, y + (12 * this->scale), colonSize, colonSize, colonColour);
      display->fillRect(xColonPos, y + (8 * this->scale), colonSize, colonSize, colonColour);
    }
    int calculateWidth() {
      return (this->sizeOfValue * TETRIS_DISTANCE_BETWEEN_DIGITS) - 1;
    }
    bool _debug = false;
    int scale = 1;
    bool drawOutline = false;
    uint16_t outLineColour = 0x0000;

    static const uint16_t tetrisRED = 0xF800;
    static const uint16_t tetrisGREEN = 0x07E0;
    static const uint16_t tetrisBLUE = 0x325F;
    static const uint16_t tetrisWHITE = 0xFFFF;
    static const uint16_t tetrisYELLOW = 0xFFE0;
    static const uint16_t tetrisCYAN = 0x07FF;
    static const uint16_t tetrisMAGENTA = 0xF81F;
    static const uint16_t tetrisORANGE = 0xFB00;
    static const uint16_t tetrisBLACK = 0x0000;
    uint16_t tetrisColors[9] = {tetrisRED, tetrisGREEN, tetrisBLUE, tetrisWHITE, tetrisYELLOW, tetrisCYAN, tetrisMAGENTA, tetrisORANGE, tetrisBLACK};

  private:
    void intialiseColors();
    void resetNumStates() {
      for (int i = 0; i < TETRIS_MAX_NUMBERS; i++) {
        this->numstates[i].num_to_draw = -1;
        this->numstates[i].fallindex = 0;
        this->numstates[i].blockindex = 0;
        this->numstates[i].x_shift = 0;
      }
    }
    void drawLargerBlock(int x_pos, int y_pos, int scale, uint16_t color) {
      this->display->fillRect(x_pos, y_pos, scale, scale, color);
    }
    numstate numstates[TETRIS_MAX_NUMBERS];
    int sizeOfValue;
};



class TestTetrisAnimationCommand : public Command
{
  private:
    unsigned long timeStart = 0UL;
    char text1[100];
    TetrisMatrixDraw tetris;

  public:
    void parseArgs(std::vector<std::string> args) override {
      strcpy(text1, args.at(0).c_str());
      tetris.scale = 2;
      tetris.setTime(text1, true);
    }

    void execute(DMD3 *canvas)  override {
      if ( millis() - timeStart > 200) {
        
        clearSerialMonitor();
        canvas->clear();
        tetris.setDisplay(canvas);
        tetris.drawNumbers(10,26, true);
        printCanvas(canvas);
        canvas->update();
        timeStart = millis();
      }
    }
};
