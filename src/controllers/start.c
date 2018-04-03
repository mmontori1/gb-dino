#include "start.h"

void setupStart(State *state){
	start_button = startGame;
	state->num_bkg = 0;
	state->num_sprites = 0;
}

void startGame(State *state){
	updateState(state, GAME);
	waitpadup();
}
