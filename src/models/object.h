#ifndef OBJECT_H
#define OBJECT_H

#include <asm/types.h>
#include <rand.h>

typedef struct Object_s {
	UINT16 x;
	UINT16 y;
	UINT8 startTile;
	UINT8 numTiles;
} Object;

extern Object player;
#define player_x 32
#define player_y 120

#define enemy_x 160
#define cactus_y 128
#define fly_y 104

void objectInit(Object* temp, UINT8 x, UINT8 y, UINT8 startTile, UINT8 numTiles);

#endif
