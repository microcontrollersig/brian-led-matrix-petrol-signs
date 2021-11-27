#pragma once

#include "DinoStart.h"
#include "SmallCactus1.h"
#include "Track-part0.h"

typedef struct  {
 const uint8_t* obj;
 int length;
 int width;
} DinoMetadata;

const DinoMetadata DinoCactusCollection[1] = {
  {.obj = SmallCactus1, .length = 8, .width = 8 }
};

const DinoMetadata DinoDinoCollection[1] = {
  {.obj = DINOSTART, .length = DINOSTART_LENGTH, .width = DINOSTART_WIDTH}
};

const DinoMetadata DinoTrackCollection[1] = {
  {.obj = TRACK_PART0, .length = TRACK_PART0_LENGTH, .width = TRACK_PART0_WIDTH  }
}; 

const static DinoMetadata* DinoObjectTypes[3] = {
  DinoTrackCollection,
  DinoCactusCollection,
  DinoDinoCollection
};






