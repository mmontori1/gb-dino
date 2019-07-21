#include "start.h"
#include <stdio.h>

#define num_start_objects 1

Object *start_objects[1] = {
	&selector
};

void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	start_button = startGame;
	state.numBkg = 0;
	state.sprites = start_objects;
	// state.numSprites = 1;
}

void startGame(){
	updateState(GAME, 1);
	waitpadup();
}
