#include "start.h"

void setupStart(){
	start_button = startGame;
	state.num_bkg = 0;
	// printf("start\n");
}

void startGame(){
	updateState(GAME);
	waitpadup();
}
