#include "start.h"
#include <stdio.h>

void setupStart(){
	start_button = startGame;
	state.numBkg = 0;
	state.numSprites = 0;
}

void startGame(){
	updateState(GAME, 0);
	waitpadup();
}
