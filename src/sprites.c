#include <gb/gb.h>
#include <sprites.h>
#include <global.h>
#include <data.h>

void game_sprites(){
	draw_sprites();
}

void draw_sprites(){
	SPRITES_8x8;
	set_sprite_data(0, 7, hacker);
	x = 32;
	y = 120;
	for(i = 0; i < 6; ++i){
		set_sprite_tile(i, i + 1);
		move_sprite(i, x + 8 * (i % 2), y + 8 * (i / 2));
	}
}
