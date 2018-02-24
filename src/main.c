#include <gb/gb.h>
#include <stdio.h>
#include "main.h"
#include "models/gameState.h"
#include "models/object.h"
#include "models/data.h"

void main() {
	init();

	while(1) {
		// Logic (controllers manipulate models)
		
		// Draw (view draw based on models)

	}
}

void init() {
	disable_interrupts();
	DISPLAY_OFF;

	SPRITES_8x8;
	/*
		* init models
			-> player, cactus, fly, gameState
			-> objectInit(&player, player_x, player_y, 0, 6);
			-> objectInit(&enemy, enemy_x, cactus_x, 33, 4);
			-> state = START
		* set game state
			-> state = START;
		* sprite data func here
			-> set_sprites(state)
		* bkg data func here
			-> set_bkg(state)
		* clear screen 
			-> draw_sprites(CLEAR)
			-> draw_bkg(CLEAR)
		* sprite draw func here
			-> draw_sprites(state)
		* bkg draw func here
			-> draw_bkg(state)
	*/
	SHOW_BKG;
	SHOW_SPRITES;

	DISPLAY_ON;
	enable_interrupts();
}
