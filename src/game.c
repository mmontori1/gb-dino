#include <stdio.h>
#include <gb/gb.h>
#include <time.h>
#include "main.h"
#include "game.h"
#include "global.h"
#include "sprites.h"
#include "background.h"

void run_game(){
	game_init();

	while(1){
		wait_vbl_done();
		input();
		update();
	}
}

void game_init(){
	game_bkg();
	game_sprites();
	update_switches();
}

void update(){
	t = clock();
	if(frame1 != t){
		frame1 = t;
		jump();
	}

	t = clock() / 2;
	if(frame2 != t){
		frame2 = t;
		scroll_bkg(1, 0);
	}

	t = clock() / 5;
	if(frame5 != t){
		frame5 = t;
		draw_sprites();
	}
}

void input(){
	switch(joypad()) {
		case J_START :
			pause();
			break;
		case J_SELECT :
			draw_bkg(CLEAR);
		case J_A : 
			jump_flag = 1;
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
