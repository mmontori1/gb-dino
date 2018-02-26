#include "window.h"

/*
	once i have window to draw, try to add this into main:

	STAT_REG |= 0x40; // enable LYC=LY interrupt
	LYC_REG = 0; // the scanline on which to trigger
	disable_interrupts();
	add_LCD(hideWin);
	enable_interrupts();
	set_interrupts(LCD_IFLAG|VBL_IFLAG);

	void hideWin(){
		HIDE_WIN;
	}
*/