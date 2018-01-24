#include <gb/gb.h>
#include <time.h>
#include <main.h>
#include <game.h>
#include <global.h>
#include <background.h>

void run_game(){

	game_init();

	while(1){
		wait_vbl_done();
		input();
		move_bkg();
	}
}

void game_init(){
	game_bkg();
	update_switches();
}

void input(){
	switch(joypad()) {
		case J_START :
			pause();
			break;
		case J_SELECT :
			set_bkg(CLEAR);
			break;
	}
}

void pause(){
	waitpadup();
	waitpad(J_START);
	waitpadup();
}

void update_switches(){
	HIDE_WIN;
	SHOW_SPRITES;
	SHOW_BKG;
}
