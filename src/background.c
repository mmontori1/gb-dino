#include <gb/gb.h>
#include <time.h>
#include <global.h>
#include <bg_data.h>
#include <background.h>

void game_bkg(){
	set_bkg_data(0, 8, bg_data);
	set_bkg(GAME);
}

void set_bkg(enum Flag flag_in){
	switch(flag_in){
		case GAME:
			set_bkg_tiles(0, 0, 36, 18, ground);
			break;
		case CLEAR:
			set_bkg_tiles(0, 0, 36, 18, blank);
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
