#include "over.h"

Object selector;

Object *over_objects[1] = {
	&selector
};

Dimension screen_dimension;
Backdrop screen;

Backdrop *over_bkg[1] = {
	&screen
};

typedef enum Option {
	CONTINUE,
	QUIT
} Option;

#define option_size 2
UINT8 selectorPosition;
Option selectorChoice[option_size] = {
	CONTINUE,
	QUIT
};

#define selector_x 40
#define selector_y 96

void setupOver(){
	LYC_REG = 0x0; //window layer off screen
	
	selectorPosition = 0;
	updateSelector();
	setupSelector(&selector, selector_x, selector_y);

	up_button = selectorUp;
	down_button = selectorDown;
	state.score = 0;
	state.bkg = over_bkg;
	state.numBkg = 1;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = over_objects;
	state.numSprites = 1;
}

void initOver(){
	screen_dimension.x = 0;
	screen_dimension.y = 0;
	screen_dimension.width = 20;
	screen_dimension.height = 18;

	screen.dimension = &screen_dimension;
	screen.tiles = game_over_map;
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
		moveSelector(selector_x, selector_y  + (selectorPosition * 16));
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
		case CONTINUE :
			start_button = restartGame;
			a_button = restartGame;
			break;
		case QUIT :
			start_button = returnToMenu;
			a_button = returnToMenu;
			break;
	}
}
