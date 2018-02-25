#include "game.h"

void setupGame(){
	// init sprite, bkg, window game data
	// init player, enemy1, enemy2 objects
	// init state score

	state.score = 0;

	setObject(&player, player_x, player_y, 0, 6);
	setObject(&enemyOne, enemy_x, 0, 0, 0);
	setObject(&enemyTwo, enemy_x, 0, 0, 0);
	
	VBL_FLAG_ON;
}

void setGameData(){
	set_sprite_data(0, 24, hacker_tiles);
	set_sprite_data(24, 9, fly_tiles);
	set_sprite_data(33, 4, cactus_tiles);
}
