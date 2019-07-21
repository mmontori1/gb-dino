#include "selector.h"

#include <gb/gb.h>

Object selector;

Dimension selector_dimension;

Frames selector_only_frames;
Frames *selector_frames[1] = {
	&selector_only_frames
};

void initSelector(){
	selector_dimension.x = 60;
	selector_dimension.y = 60;
	selector_dimension.width = 1;
	selector_dimension.height = 1;

	selector_only_frames.numFrames = selector_max_frames;
	selector_only_frames.frames = selector_only_data;

	selector.startTile = 45;
	selector.numTiles = 1;
	selector.frameCount = 0;
	selector.maxFrames = selector_max_frames;
	selector.dimension = &selector_dimension;
	selector.frames = selector_frames;
}

void setSelectorData(){
	set_sprite_data(45, 1, selector_tiles);
}
