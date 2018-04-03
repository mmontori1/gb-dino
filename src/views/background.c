#include "background.h"

UINT8 i;

void clearBkg(){
	set_bkg_tiles(0, 0, 32, 18, blank_map);
}

void drawBkg(State *state){
	for(i = 0; i < state->num_bkg; ++i){
		set_bkg_tiles(
			state->bkg[i]->dimension->x, 
			state->bkg[i]->dimension->y, 
			state->bkg[i]->dimension->width, 
			state->bkg[i]->dimension->height, 
			state->bkg[i]->tiles
		);
	}

	SHOW_BKG;
}
