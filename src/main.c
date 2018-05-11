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
	SHOW_WIN;
	if(VBL_FLAG){
		if(state.setData != NULL) state.setData();
		drawBkg(state.bkg, state.numBkg);
		drawWin(state.win, state.numWin);
		VBL_FLAG_OFF;
	}
}

void hideWin(){
	HIDE_WIN;
}

void init() {
	STAT_REG = 0x45;
    LYC_REG = 0x18; //top three 8x8 lines for window

	disable_interrupts();
	DISPLAY_OFF;
	SPRITES_8x8;

	updateState(&state, START);

	add_VBL(vblCallback);
	add_LCD(hideWin);

	clearBkg();
	initGame();
	SHOW_BKG;
	SHOW_SPRITES;
	SHOW_WIN;

	DISPLAY_ON;
	enable_interrupts();

    set_interrupts(VBL_IFLAG | LCD_IFLAG);
}
