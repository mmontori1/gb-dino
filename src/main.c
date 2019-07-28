#include "main.h"

UBYTE hasInit = 0;

void main() {
	init();
	while(1) {
		wait_vbl_done();
		// Logic (controllers manipulate models or data)

		checkInput();
		if(state.updateLogic != NULL) state.updateLogic();
		drawWin(state.win, state.numWin);

		wait_vbl_done();
		// Draw (views draw screen based on models)
		drawSprites(state.sprites, state.numSprites);
	}
}

// handles applying sprite, window, or background data during vblank interrupt
void vblCallback(){
	if(hasInit) {
		SHOW_WIN;

		if(VBL_FLAG){
			if(state.setData != NULL) state.setData();

			drawBkg(state.bkg, state.numBkg);
			VBL_FLAG_OFF;
		}
	}
}

void hideWin(){
	HIDE_WIN;
}

void init() {
	STAT_REG = 0x45;

	disable_interrupts();
	DISPLAY_OFF;
	SPRITES_8x8;

	updateState(START);

	add_VBL(vblCallback);
	add_LCD(hideWin);

	printf(" ");
	clearBkg();
	setGameData();
	setSelectorData();
	initStart();
	initGame();
	initOver();
	SHOW_BKG;
	SHOW_SPRITES;
	SHOW_WIN;

	DISPLAY_ON;
	enable_interrupts();

    set_interrupts(VBL_IFLAG | LCD_IFLAG);
    hasInit = 1;
}
