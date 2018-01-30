#include <gb/gb.h>
#include <stdio.h>
#include <time.h>
#include "sprites.h"
#include "global.h"
#include "data.h"

UINT8 hacker_midleft_data[8] = {3, 5, 7, 3, 3, 8, 10, 3};
UINT8 hacker_midright_data[8] = {4, 6, 6, 4, 4, 9, 11, 4};
UINT8 hacker_botleft_data[8] = {12, 14, 16, 18, 12, 20, 22, 20};
UINT8 hacker_botright_data[8] = {13, 15, 17, 19, 13, 21, 23, 21};

void game_sprites(){
	SPRITES_8x8;
	a = 0;
	p = -1;
	x = 32;
	y = 120;
	set_sprite_data(0, 24, hacker);

	set_sprite_tile(0, 1);
	set_sprite_tile(1, 2);
	set_sprite_tile(2, hacker_midleft_data[a]);
	set_sprite_tile(3, hacker_midright_data[a]);
	set_sprite_tile(4, hacker_botleft_data[a]);
	set_sprite_tile(5, hacker_botright_data[a]);

	for(i = 0; i < 6; ++i){
		move_sprite(i, x + 8 * (i % 2), y + 8 * (i / 2));
	}
}

void draw_sprites(){
	t = clock() / 5;
	if(frame1 != t){
		frame1 = t;
		set_sprite_tile(2, hacker_midleft_data[a]);
		set_sprite_tile(3, hacker_midright_data[a]);
		set_sprite_tile(4, hacker_botleft_data[a]);
		set_sprite_tile(5, hacker_botright_data[a]);

		if(a % 2 == 0){
			p = (a < 4) ? p + 1 : p - 1;
		}

		for(i = 0; i < 6; ++i){
			move_sprite(i, x + 8 * (i % 2), y + 8 * (i / 2) + p);
		}

		a = (a + 1 == 8) ? 0 : a + 1;
	}
}
