#ifndef OBJECT_H
#define OBJECT_H

#include <asm/types.h>
#include <rand.h>
#include "animator.h"
#include "dimension.h"

typedef struct Object_s {
	UINT8 startTile;
	UINT8 numTiles;
	Dimension* dimension;
	Animator* animator;
} Object;

#define player_x 32
#define player_y 120

#define enemy_x 160
#define cactus_y 128
#define fly_y 104

// void setObject(Object* temp, UINT8 x, UINT8 y, UINT8 startTile, UINT8 numTiles, UINT8 width, UINT8 height, Animator* animator);

#endif
