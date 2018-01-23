#include <gb/gb.h>
#include <main.h>
#include <time.h>
#include <sprites.h>
#include <stdio.h>

void main() {
	int i = 0;
	// DISPLAY_ON;

	game_init();

	// set_bkg_data(0, 12, mh);
	// set_bkg_tiles(
	// 	0,
	// 	9, 
	// 	16, 
	// 	1, 
	// 	mh_map
	// );
	update_switches();

	while(1){
		wait_vbl_done();
		input();
		// printf("%d\n", clock() % 10);
		if(i != clock()){
			i = clock();
			scroll_bkg(1, 0);
		}
		// else {

		// }
		// delay(15);
	}
}

void sprites(){
	/*
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
	*/
}

void input(){
	switch(joypad()) {
		case J_START :
			pause();
			break;
		case J_SELECT :
			clr_bkg();
			break;
	}
}

void pause(){
	waitpadup();
	waitpad(J_START);
	waitpadup();
}

void clr_bkg(){
	set_bkg_tiles(0, 0, 36, 18, blank);
	SHOW_BKG;
}

void update_switches(){
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
}

void game_init(){
	set_bkg_data(0, 7, bg_data);
	set_bkg_tiles(
		0,
		0, 
		36, 
		18, 
		ground
	);
	update_switches();
}
