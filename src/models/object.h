#ifndef OBJECT_H
#define OBJECT_H

#include <asm/types.h>
#include "frames.h"
#include "dimension.h"

typedef struct Object_s {
	UINT8 startTile;
	UINT8 numTiles;
	UINT8 frameCount;
	UINT8 maxFrames;
	Dimension* dimension;
	Frames** frames;
} Object;

#define player_x 32
#define player_y 120

#define enemy_x 168
#define cactus_y 128
#define fly_high_y 104
#define fly_low_y 112

#endif
