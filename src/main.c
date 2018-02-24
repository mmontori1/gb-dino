#include <gb/gb.h>
#include <stdio.h>
#include "main.h"

void main() {
	init();
	printf("hello world");
}

void init() {
	disable_interrupts();
	DISPLAY_OFF;

	SPRITES_8x8;
	/*
		* clear screen 
			-> draw_sprites(CLEAR)
			-> draw_bkg(CLEAR)
		* set game state
			-> state = START;
		* sprite data func here
			-> set_sprites(state)
		* sprite draw func here
			-> draw_sprites(state)
		* bkg data func here
			-> set_bkg(state)
		* bkg draw func here
			-> draw_bkg(state)
	*/
	SHOW_BKG;
	SHOW_SPRITES;

	DISPLAY_ON;
	enable_interrupts();
}
