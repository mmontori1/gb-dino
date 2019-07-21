#include "start.h"
#include <stdio.h>

void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	start_button = startGame;
	state.numBkg = 0;
	state.numSprites = 0;
}

void startGame(){
	updateState(GAME, 0);
	waitpadup();
}
