#include "window.h"

UINT8 i;

void drawWin(Backdrop **win, UINT8 numWin){
	for(i = 0; i < numWin; ++i){
		set_win_tiles(
			win[i]->dimension->x, 
			win[i]->dimension->y, 
			win[i]->dimension->width, 
			win[i]->dimension->height, 
			win[i]->tiles
		);
	}

	SHOW_WIN;
}
