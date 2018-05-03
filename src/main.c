#include "main.h"

State state;

void main() {
	init();
	while(1) {
		wait_vbl_done();

		// Logic (controllers manipulate models or data)
		checkInput(&state);
		if(state.updateLogic != NULL) state.updateLogic();
		
		// Draw (views draw screen based on models)
		/*
			* make wrapper views.c with draw logic
			* sprite draw func here
				-> draw_sprites(state.type)
			* window draw func here
				-> draw_window(state.type)
			* bkg draw func here
				-> draw_bkg(state.type)
		*/
		drawBkg(&state);
		drawSprites(&state);
	}
}

// handles applying sprite, window, or background data during vblank interrupt
void vblCallback(){
	if(VBL_FLAG){
		if(state.setData != NULL) state.setData();
		VBL_FLAG_OFF;
	}
}

void init() {
	disable_interrupts();
	DISPLAY_OFF;

	SPRITES_8x8;

	updateState(&state, START);
	add_VBL(vblCallback);
	/*
		* clear screen 
			-> draw_sprites(CLEAR)
	*/
	clearBkg();
	initGame();
	SHOW_BKG;
	SHOW_SPRITES;

	DISPLAY_ON;
	enable_interrupts();
}
