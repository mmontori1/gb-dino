#include "start.h"
#include <stdio.h>

#define num_start_objects 1

Object selector;

Object *start_objects[1] = {
	&selector
};

void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	setupSelector(&selector, 60, 60);

	start_button = startGame;
	state.numBkg = 0;
	state.bkg = NULL;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = start_objects;
	state.numSprites = 1;
}

void startGame(){
	clearAll();
	updateState(GAME);
	waitpadup();
}
