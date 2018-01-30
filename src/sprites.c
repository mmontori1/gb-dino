#include <gb/gb.h>
#include <stdio.h>
#include <time.h>
#include "sprites.h"
#include "global.h"
#include "data.h"

// maybe move initialization of arrays into init func?
UINT8 hacker_midleft_data[8] = {3, 5, 7, 3, 3, 8, 10, 3};
UINT8 hacker_midright_data[8] = {4, 6, 6, 4, 4, 9, 11, 4};
UINT8 hacker_botleft_data[8] = {12, 14, 16, 18, 12, 20, 22, 20};
UINT8 hacker_botright_data[8] = {13, 15, 17, 19, 13, 21, 23, 21};
UINT8 *hacker_data[4] = {
	&hacker_midleft_data, 
	&hacker_midright_data, 
	&hacker_botleft_data,
	&hacker_botright_data
};

void game_sprites(){
	SPRITES_8x8;

	// move sprite specific globals in-file to avoid errors: a, j, k, p
	a = 0;
	j = 0;
	k = 0;
	p = 0;
	set_sprite_data(0, 24, hacker);
	
	set_hacker_head();
	set_hacker_body(0);

	move_hacker(0);
}

void draw_sprites(){
	t = clock() / 5;
	if(frame1 != t){
		frame1 = t;
		if(!jump_flag){
			set_hacker_body(a);
			a = (a + 1 == 8) ? 0 : a + 1;
		}
		else {
			set_hacker_body(5);
			a = 0;
		}
	}
	if(jump_flag){
		jump();
	}
}

void set_hacker_head(){
	// head is constant, don't need to change
	set_sprite_tile(0, 1);
	set_sprite_tile(1, 2);
}

void set_hacker_body(UINT8 frame){
	// body at specified frame location in data
	for(i = 2; i < 6; ++i){
		set_sprite_tile(i, hacker_data[i - 2][frame]);
	}
}

/* MIGRATE ALL BELOW TO PHYSICS.C EVENTUALLY */

void move_hacker(UINT8 push){
	// move hacker on screen
	for(i = 0; i < 6; ++i){
		move_sprite(i, hacker_x + 8 * (i % 2), hacker_y + 8 * (i / 2) + push);
	}
}

void jump(){
	t = clock();
	if(frame3 != t){
		frame3 = t;
		jump_flag = (j + 1 == 40) ? 0 : 1;
		if((j >= 0 && j < 7) || (j >= 33 && j < 40)){
			k = 3;
		}
		else if((j >= 7 && j < 13) || (j >= 27 && j < 33)){
			k = 2;
		}
		else if((j >= 13 && j < 18) || (j >= 22 && j < 27)){
			k = 1;
		}
		else {
			k = 0;
		}
		p = (j < 20) ? p - k : p + k;
		j = (j + 1 == 40) ? 0 : j + 1;

		move_hacker(p);
	}
}
