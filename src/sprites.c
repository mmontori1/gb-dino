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
	// move sprite specific globals in-file to avoid errors: a, j, k, p
	a = 0;
	j = 0;
	k = 0;
	p = 0;
	set_sprite_data(0, 24, hacker);
	set_sprite_data(24, 33, fly);
	set_sprite_data(33, 37, cactus);
	for(i = 0; i < 4; ++i){
		set_sprite_tile(6 + i, 33 + i);
		move_sprite(6 + i, 140 + 8 * (i % 2), 128 + 8 * (i / 2));
	}
	set_hacker_head();
	set_hacker_body(0);

	move_hacker(0);
}

void draw_sprites(){
	if(!jump_flag){
		set_hacker_body(a);
		a = (a + 1 == 8) ? 0 : a + 1;
	}
	else {
		set_hacker_body(5);
		a = 0;
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

/* MIGRATE ALL BELOW TO PHYSICS.C OR PLAYER.C EVENTUALLY */

void move_hacker(UINT8 push){
	// move hacker on screen
	for(i = 0; i < 6; ++i){
		move_sprite(i, hacker_x + 8 * (i % 2), hacker_y + 8 * (i / 2) + push);
	}
}

void jump(){
	if(jump_flag){
		if((j >= 0 && j < 7) || (j >= 40 - 7 && j < 40)){
			k = 3;
		}
		else if((j >= 7 && j < 12) || (j >= 40 - 12 && j < 40 - 7)){
			k = 2;
		}
		else if((j >= 12 && j < 17) || (j >= 40 - 17 && j < 40 - 12)){
			k = 1;
		}
		else {
			k = 0;
		}
		
		jump_flag = (j + 1 == 40) ? 0 : 1;
		p = (j < 20) ? p - k : p + k;
		j = (j + 1 == 40) ? 0 : j + 1;

		move_hacker(p);
	}
}
