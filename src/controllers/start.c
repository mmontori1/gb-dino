#include "start.h"

void setupStart(){
	start_button = startGame;
	printf("start\n");
}

void startGame(){
	updateState(GAME);
	waitpadup();
}
