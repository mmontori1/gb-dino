#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "helpers/global.h"

typedef enum Action {
	START,
	GAME,
	OVER,
	CLEAR
	//PAUSE??
} Action;

typedef struct State_s {
	Action type;
	UINT16 score;
	void (*setData) ();
} State;

extern State state;

#endif
