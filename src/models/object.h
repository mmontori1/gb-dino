#ifndef OBJECT_H
#define OBJECT_H

#include <asm/types.h>

// always declare struct at the top of a func!!!

typedef struct Object_s {
	UINT16 x;
	UINT16 y;
	UINT8 startTile;
	UINT8 numTiles;
} Object;

#define player_x 32
#define player_y 120
extern Object player;

#define enemy_x 160
#define cactus_y 128
// #define fly_y
// #define fly_y_range

void objectInit(Object* temp, UINT8 x, UINT8 y, UINT8 startTile, UINT8 numTiles);

#endif
