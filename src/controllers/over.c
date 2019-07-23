#include "over.h"

Object selector;

Object *over_objects[1] = {
	&selector
};

Dimension over_screen_dimension;
Backdrop over_screen;

Backdrop *over_bkg[1] = {
	&over_screen
};

typedef enum Option {
	OVER_CONTINUE,
	OVER_QUIT
} Option;

#define option_size 2
UINT8 selectorPosition;
Option selectorChoice[option_size] = {
	OVER_CONTINUE,
	OVER_QUIT
};

#define selector_over_x 40
#define selector_over_y 96

void setupOver(){
	LYC_REG = 0x0; //window layer off screen
	
	selectorPosition = 0;
	updateSelector();
	setupSelector(&selector, selector_over_x, selector_over_y);

	up_button = selectorUp;
	down_button = selectorDown;
	state.bkg = over_bkg;
	state.numBkg = 1;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = over_objects;
	state.numSprites = 1;
}

void initOver(){
	over_screen_dimension.x = 0;
	over_screen_dimension.y = 0;
	over_screen_dimension.width = 20;
	over_screen_dimension.height = 18;

	over_screen.dimension = &over_screen_dimension;
	over_screen.tiles = game_over_map;
}

void restartGame(){
	clearAll();
	updateState(GAME);
	waitpadup();
}

void returnToMenu(){
	clearAll();
	updateState(START);
	waitpadup();
}

void updateSelector(){
	if(selectorPosition >= 0 && selectorPosition < option_size){
		moveSelector(selector_over_x, selector_over_y  + (selectorPosition * 16));
		selectorSelectOption();
	}
}

void selectorUp(){
	selectorPosition = 0;
	updateSelector();
}

void selectorDown(){
	selectorPosition = 1;
	updateSelector();
}

void selectorSelectOption(){
	switch(selectorChoice[selectorPosition]){
		case OVER_CONTINUE :
			start_button = restartGame;
			a_button = restartGame;
			break;
		case OVER_QUIT :
			start_button = returnToMenu;
			a_button = returnToMenu;
			break;
	}
}
