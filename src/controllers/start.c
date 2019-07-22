#include "start.h"
#include <stdio.h>

#define num_start_objects 1

Object selector;

Object *start_objects[1] = {
	&selector
};

Dimension selector_dimension;

Frames selector_only_frames;
Frames *selector_frames[1] = {
	&selector_only_frames
};


void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	setSelector();

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

void initSelector(){
	setSelectorData();
	setSelector();
}

void setSelector(){
	selector_dimension.x = 60;
	selector_dimension.y = 60;
	selector_dimension.width = 1;
	selector_dimension.height = 1;

	selector_only_frames.numFrames = selector_max_frames;
	selector_only_frames.frames = selector_only_data;

	selector.startTile = 18;
	selector.numTiles = 1;
	selector.frameCount = 0;
	selector.maxFrames = selector_max_frames;
	selector.dimension = &selector_dimension;
	selector.frames = selector_frames;
}

void setSelectorData(){
	set_sprite_data(45, 1, selector_tiles);
}
