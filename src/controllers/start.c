#include "start.h"

void setupStart(){
	clearInputs();
	start_button = startGame;
}

void startGame(){
	updateState(GAME);
	waitpadup();
}
