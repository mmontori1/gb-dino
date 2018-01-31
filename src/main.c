#include <gb/gb.h>
#include "main.h"
#include "game.h"

void main() {
	init();
	run_game();
}

void init() {
	DISPLAY_ON;
	SPRITES_8x8;
}
