#include <gb/gb.h>
#include <time.h>
#include "global.h"
#include "data.h"
#include "background.h"

void game_bkg(){
	set_bkg_data(0, 2, ground_tiles);
	draw_bkg(CLEAR);
	draw_bkg(GAME);
}

void draw_bkg(enum Flag flag_in){
	switch(flag_in){
		case GAME:
			set_bkg_tiles(
				0, 
				16, 
				screen_wrap_width, 
				ground_height, 
				ground_map
			);
			break;
		case CLEAR:
			set_bkg_tiles(
				0, 
				0, 
				screen_wrap_width, 
				screen_height, 
				blank_map
			);
			break;
	}
}

void move_bkg(){
	t = clock();
	if(frame != t){
		frame = t;
		scroll_bkg(1, 0);
	}
}
