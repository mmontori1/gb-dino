#include "background.h"

UINT8 i;

void drawBkg(Backdrop **bkg, UINT8 numBkg){
	for(i = 0; i < numBkg; ++i){
		set_bkg_tiles(
			bkg[i]->dimension->x, 
			bkg[i]->dimension->y, 
			bkg[i]->dimension->width, 
			bkg[i]->dimension->height, 
			bkg[i]->tiles
		);
	}

	SHOW_BKG;
}
