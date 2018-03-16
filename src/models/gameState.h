#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "helpers/global.h"
#include "object.h"
#include "dimension.h"
#include "backdrop.h"

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
	Backdrop **bkg;
	UINT8 num_bkg;
} State;

extern State state;

#endif
