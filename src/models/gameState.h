#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <asm/types.h>

/*
	How to create a flag:
	UINT8 JUMP;
	#define JUMP_ON JUMP |= (1 << 0);
	#define JUMP_OFF JUMP &= ~(1 << 0)

	How to create a rand num 0-7:
	#include <rand.h>
	INT8 randnum;
	randnum = rand() & 7;
*/

typedef enum Action {
	START,
	GAME,
	OVER,
	CLEAR
} Action;

typedef struct State_s {
	Action type;
	UINT16 highScore;
} State;

extern State state;

#endif
