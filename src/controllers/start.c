#include "start.h"

void setupStart(){
	start_button = startGame;

	VBL_FLAG_ON;
}

void startGame(){
	updateState(GAME);
	waitpadup();
}
