#ifndef OBJECT_H
#define OBJECT_H

#include <asm/types.h>
#include <rand.h>

typedef enum Animate {
	CONSTANT,
	DYNAMIC
} Animate;

typedef struct Animator_s {
	Animate *type;	// should be of size of num sprites
	UINT8 numFrames;
	UINT8 **frames;	// should be 2d arr of size [num dynamic sprites][numFrames]
} Animator;

typedef struct Object_s {
	UINT16 x;
	UINT16 y;
	UINT8 startTile;
	UINT8 numTiles;
	UINT8 width;
	UINT8 height;
	Animator* animator;
} Object;

extern Animator player_animator;
extern Object player;
extern Object enemyOne;
extern Object enemyTwo;

#define player_x 32
#define player_y 120

#define enemy_x 160
#define cactus_y 128
#define fly_y 104

void setObject(Object* temp, UINT8 x, UINT8 y, UINT8 startTile, UINT8 numTiles, UINT8 width, UINT8 height, Animator* animator);

#endif
