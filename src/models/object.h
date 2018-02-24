#ifndef OBJECT_H
#define OBJECT_H

#include <asm/types.h>

struct Object_s {
	UINT16 x;
	UINT16 y;
	UINT8 startTile;
	UINT8 numTiles;
};

typedef struct Object_s Object;

extern Object player;

void objectInit(Object* temp, UINT8 x, UINT8 y, UINT8 startTile, UINT8 numTiles);

#endif
