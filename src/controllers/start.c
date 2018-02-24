#include "start.h"

void setupStart(){
	start_button = startGame;
}

void startGame(){
	updateState(GAME);
	waitpadup();
}
