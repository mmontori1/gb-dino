#include "start.h"

void setupStart(State *state){
	start_button = startGame;
	state->numBkg = 0;
	state->numSprites = 0;
}

void startGame(State *state){
	updateState(state, GAME);
	waitpadup();
}
