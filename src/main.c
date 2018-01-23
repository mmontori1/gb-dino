#include <gb/gb.h>
#include <main.h>
#include <sprites.h>
#include <stdio.h>

void main() {
	DISPLAY_ON;
	// set_bkg_data(0, 1, blankTile);
	set_bkg_data(0, 7, tiles);
	set_bkg_tiles(0, 0, 40, 18, ground);
	SHOW_BKG;
	while(1){
		input();
		scroll_bkg(1, 0);
		delay(15);
	}
}

void sprites(){
	int i = 0;
	int x = 8;
	int y = 152;
	
	SPRITES_8x8;
	set_sprite_data(0, 2, bg);
	set_sprite_tile(0, 0);

	SHOW_SPRITES;
	while(1){
		input();
		i = 0;
		++x;
		while(i < 10){
			move_sprite(i, x + 8 * i, y);
			++i;
		}
		delay(10);
	}
}

void input(){
	switch(joypad()) {
		case J_START :
			pause();
			break;
		case J_SELECT :
			clrbkg();
			break;
	}
}

void pause(){
	waitpadup();
	waitpad(J_START);
	waitpadup();
}

void clrbkg(){
	set_bkg_data(0, 0, blankTile);
	set_bkg_tiles(0, 0, 20, 18, blank);
}
