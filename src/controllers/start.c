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

Option selectorStartChoice[option_size] = {
	OPTION_1,
	OPTION_2
};

#define selector_start_x 52
#define selector_start_y 96

void setupStart(){
	LYC_REG = 0x0; //window layer off screen

	selectorPosition = 0;
	setupSelector(&selector, selector_start_x, selector_start_y);
	updateSelector(selectorStartOption, selector_start_x, selector_start_y);

	up_button = selectorStartUp;
	down_button = selectorStartDown;
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
	set_win_data(10, 32, title_tiles);
}

void startGame(){
	clearAll();
	updateState(GAME);
	waitpadup();
}

void selectorStartOption(){
	switch(selectorStartChoice[selectorPosition]){
		case OPTION_1 :
			start_button = startGame;
			a_button = startGame;
			break;
		case OPTION_2 :
			start_button = NULL;
			a_button = NULL;
			break;
	}
}

void selectorStartUp(){
	selectorPosition = 0;
	updateSelector(selectorStartOption, selector_start_x, selector_start_y);
}

void selectorStartDown(){
	selectorPosition = 1;
	updateSelector(selectorStartOption, selector_start_x, selector_start_y);
}
