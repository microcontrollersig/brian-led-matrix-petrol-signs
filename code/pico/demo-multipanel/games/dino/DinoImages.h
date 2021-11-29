#pragma once

#include "DinoStart.h"
#include "SmallCactus1.h"
#include "Track-part0.h"
#include "Track-part1.h"
#include "Track-part2.h"

typedef struct {
  const uint8_t *obj;
  int length;
  int width;
} DinoMetadata;

const DinoMetadata DinoCactusCollection[1] = {
    {.obj = SmallCactus1, .length = 8, .width = 8}};

const DinoMetadata DinoDinoCollection[1] = {
    {.obj = DINOSTART, .length = DINOSTART_LENGTH, .width = DINOSTART_WIDTH}};

const DinoMetadata DinoTrackCollection[3] = {{.obj = TRACK_PART0,
                                              .length = TRACK_PART0_LENGTH,
                                              .width = TRACK_PART0_WIDTH},
                                             {.obj = TRACK_PART1,
                                              .length = TRACK_PART1_LENGTH,
                                              .width = TRACK_PART1_WIDTH},
                                             {.obj = TRACK_PART2,
                                              .length = TRACK_PART2_LENGTH,
                                              .width = TRACK_PART2_WIDTH}};

const static DinoMetadata *DinoObjectTypes[3] = {
    DinoTrackCollection, DinoCactusCollection, DinoDinoCollection};
