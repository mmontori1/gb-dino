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

Option selectorOverChoice[option_size] = {
	OPTION_1,
	OPTION_2
};

#define selector_over_x 40
#define selector_over_y 104

void setupOver(){
	LYC_REG = 0x0; //window layer off screen
	
	selectorPosition = 0;
	setupSelector(&selector, selector_over_x, selector_over_y);
	updateSelector(selectorOverOption, selector_over_x, selector_over_y);

	up_button = selectorOverUp;
	down_button = selectorOverDown;
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

void selectorOverOption(){
	switch(selectorOverChoice[selectorPosition]){
		case OPTION_1 :
			start_button = restartGame;
			a_button = restartGame;
			break;
		case OPTION_2 :
			start_button = returnToMenu;
			a_button = returnToMenu;
			break;
	}
}

void selectorOverUp(){
	selectorPosition = 0;
	updateSelector(selectorOverOption, selector_over_x, selector_over_y);
}

void selectorOverDown(){
	selectorPosition = 1;
	updateSelector(selectorOverOption, selector_over_x, selector_over_y);
}
