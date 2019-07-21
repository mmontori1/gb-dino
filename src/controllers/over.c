#include "over.h"

Dimension screen_dimension;
Backdrop screen;

Backdrop *over_bkg[1] = {
	&screen
};

void setupOver(){
	start_button = restartGame;
	state.score = 0;
	state.bkg = over_bkg;
	state.numBkg = 1;
	state.win = NULL;
	state.numWin = 0;
	state.sprites = NULL;
	state.numSprites = 0;
}

void initOver(){
	screen_dimension.x = 3;
	screen_dimension.y = 6;
	screen_dimension.width = 14;
	screen_dimension.height = 5;

	screen.dimension = &screen_dimension;
	screen.tiles = game_over_map;
}

void restartGame(){
	updateState(START, 0);
	waitpadup();
}
