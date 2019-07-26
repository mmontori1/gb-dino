#include "start.h"
#include <stdio.h>

#define num_start_objects 1

Object selector;

Object *start_objects[num_start_objects] = {
	&selector
};

Dimension start_screen_dimension;
Backdrop start_screen;

Backdrop *start_bkg[1] = {
	&start_screen
};

#define selector_start_x 52
#define selector_start_y 96

void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	setupSelector(&selector, selector_start_x, selector_start_y);

	start_button = startGame;
	state.numBkg = 1;
	state.bkg = start_bkg;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = start_objects;
	state.numSprites = num_start_objects;
}

void initStart(){
	setStartData();

	start_screen_dimension.x = 0;
	start_screen_dimension.y = 0;
	start_screen_dimension.width = 20;
	start_screen_dimension.height = 18;

	start_screen.dimension = &start_screen_dimension;
	start_screen.tiles = main_menu_map;
}

void setStartData(){
	set_win_data(10, 31, title_tiles);
}

void startGame(){
	clearAll();
	updateState(GAME);
	waitpadup();
}
