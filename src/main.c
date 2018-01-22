#include <gb/gb.h>
#include <main.h>
#include <sprites.h>
#include <stdio.h>

void main() {
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
	}
}

void pause(){
	waitpadup();
	waitpad(J_START);
	waitpadup();
}
