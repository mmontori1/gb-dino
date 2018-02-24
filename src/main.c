#include "main.h"

void main() {
	init();
	while(1) {
		// Logic (controllers manipulate models)
		checkInput();

		// Draw (view draw based on models)

	}
}

void print(){
	printf("hello world!\n");
}

void init() {
	disable_interrupts();
	DISPLAY_OFF;

	SPRITES_8x8;
	setState(START);
	/*
		* init models
			-> player, cactus, fly, gameState
			-> setObject(&player, player_x, player_y, 0, 6);
			-> setObject(&enemy, enemy_x, cactus_x, 33, 4);
		* set game state
			-> state.type = START;
			-> state.highScore = 0;
		* sprite data func here
			-> set_sprites(state.type)
		* bkg data func here
			-> set_bkg(state.type)
		* clear screen 
			-> draw_sprites(CLEAR)
			-> draw_bkg(CLEAR)
		* sprite draw func here
			-> draw_sprites(state.type)
		* bkg draw func here
			-> draw_bkg(state.type)
	*/
	SHOW_BKG;
	SHOW_SPRITES;

	DISPLAY_ON;
	enable_interrupts();
}
