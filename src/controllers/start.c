#include "start.h"
#include <stdio.h>

void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	start_button = startGame;
	state.numBkg = 0;
	state.bkg = NULL;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = NULL;
	state.numSprites = 0;
}

void startGame(){
	clearAll();
	updateState(GAME);
	waitpadup();
}
