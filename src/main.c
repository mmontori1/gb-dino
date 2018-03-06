#include "main.h"

void main() {
	init();
	while(1) {
		wait_vbl_done();

		// Logic (controllers manipulate models or data)
		checkInput();
		updateLogic();
		
		// Draw (views draw screen based on models)
		/*
			* sprite draw func here
				-> draw_sprites(state.type)
			* window draw func here
				-> draw_window(state.type)
			* bkg draw func here
				-> draw_bkg(state.type)
		*/
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

	updateState(START);
	add_VBL(vblCallback);
	/*
		* clear screen 
			-> draw_sprites(CLEAR)
			-> draw_bkg(CLEAR)
	*/

	SHOW_BKG;
	SHOW_SPRITES;

	DISPLAY_ON;
	enable_interrupts();
}
