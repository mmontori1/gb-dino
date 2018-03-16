#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "helpers/global.h"
#include "object.h"
#include "dimension.h"

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
	Object **sprites;
	Dimension **bkg;
} State;

extern State state;

#endif
