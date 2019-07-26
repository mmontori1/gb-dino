#include "start.h"
#include <stdio.h>

// #define num_start_objects 1

// Object selector;

// Object *start_objects[1] = {
// 	&selector
// };

Dimension start_screen_dimension;
Backdrop start_screen;

Backdrop *start_bkg[1] = {
	&start_screen
};

void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	// setupSelector(&selector, 60, 60);

	start_button = startGame;
	state.numBkg = 1;
	state.bkg = start_bkg;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = NULL;
	state.numSprites = 0;
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
