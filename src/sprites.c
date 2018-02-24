#include <gb/gb.h>
#include <stdio.h>
#include <time.h>
#include "sprites.h"
#include "global.h"
#include "data.h"
#include "object.h"

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

struct object o_player;
struct object o_cactus;

void game_sprites(){
	// move sprite specific globals in-file to avoid errors: a, j, k, p
	a = 0;
	j = 0;
	k = 0;
	p = 0;

	o_player.x = 32;
	o_player.y = 120;
	o_cactus.x = 140;
	o_cactus.y = 128;

	set_sprite_data(0, 24, hacker_tiles);
	set_sprite_data(24, 33, fly_tiles);
	set_sprite_data(33, 37, cactus_tiles);
	set_hacker_head();
	set_hacker_body(0);
	set_cactus();

	move_hacker(0);
	move_cactus(0);
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
	o_player.y += push;
	for(i = 0; i < 6; ++i){
		move_sprite(i, o_player.x + 8 * (i % 2), o_player.y + 8 * (i / 2));
	}
}

void set_cactus(){
	for(i = 0; i < 4; ++i){
		set_sprite_tile(6 + i, 33 + i);
	}
}

void move_cactus(UINT8 push){
	o_cactus.x += push;
	for(i = 0; i < 4; ++i){
		move_sprite(6 + i, o_cactus.x + 8 * (i % 2), o_cactus.y + 8 * (i / 2));
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
		p = (j < 20) ? -k : k;
		j = (j + 1 == 40) ? 0 : j + 1;

		move_hacker(p);
	}
}
