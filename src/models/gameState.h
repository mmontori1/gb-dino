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
} Action;

typedef struct State_s {
	Action type;
	UINT16 score;

	void (*setData) ();
	void (*updateLogic) ();

	Backdrop **bkg;
	UINT8 numBkg;

	Backdrop **win;
	UINT8 numWin;

	Object **sprites;
	UINT8 numSprites;
} State;

extern State state;

#endif
