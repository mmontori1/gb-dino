#include "main.h"

State state;

void main() {
	init();
	while(1) {
		wait_vbl_done();

		// Logic (controllers manipulate models or data)
		checkInput(&state);
		if(state.updateLogic != NULL) state.updateLogic();

		wait_vbl_done();
		// Draw (views draw screen based on models)
		drawSprites(state.sprites, state.numSprites);
	}
}

// handles applying sprite, window, or background data during vblank interrupt
void vblCallback(){
	if(VBL_FLAG){
		if(state.setData != NULL) state.setData();
		drawBkg(state.bkg, state.numBkg);
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
