#include "over.h"

void setupOver(){
	start_button = restartGame;
	state.score = 0;
	state.bkg = NULL;
	state.numBkg = 0;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = NULL;
	state.numSprites = 0;
}

void restartGame(){
	updateState(START);
	waitpadup();
}
