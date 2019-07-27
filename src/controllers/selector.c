#include "selector.h"

#include <gb/gb.h>

Dimension selector_dimension;

Frames selector_only_frames;
Frames *selector_frames[1] = {
	&selector_only_frames
};

UINT8 selectorPosition;

void setupSelector(Object *selector, UINT8 x, UINT8 y){
	moveSelector(x, y);
	selector_dimension.width = 1;
	selector_dimension.height = 1;

	selector_only_frames.numFrames = selector_max_frames;
	selector_only_frames.frames = selector_only_data;

	selector->startTile = 18;
	selector->numTiles = 1;
	selector->frameCount = 0;
	selector->maxFrames = selector_max_frames;
	selector->dimension = &selector_dimension;
	selector->frames = selector_frames;
}

void moveSelector(UINT8 x, UINT8 y){
	selector_dimension.x = x;
	selector_dimension.y = y;
}

void setSelectorData(){
	set_sprite_data(45, 1, selector_tiles);
}

void updateSelector(void (*action)(), UINT8 x, UINT8 y){
	if(selectorPosition >= 0 && selectorPosition < option_size){
		moveSelector(x, y  + (selectorPosition * 16));
		action();
	}
}
