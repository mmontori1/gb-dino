#include <stdio.h>
#include <gb/gb.h>
#include <main.h>
#include <time.h>
#include <sprites.h>

void main() {
	int frame = 0;
	int time = 0;

	DISPLAY_ON;
	game_init();
	while(1){
		wait_vbl_done();
		input();
		time = clock();
		if(frame != time){
			frame = time;
			scroll_bkg(1, 0);
		}
	}
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
	update_switches();
}

void update_switches(){
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
}

void game_init(){	
	set_bkg_data(0, 7, bg_data);
	set_bkg_tiles(0, 0, 36, 18, ground);
	update_switches();
}
