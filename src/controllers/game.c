#include "game.h"

void setupGame(){
	Animator player_animator;
	player_animator.type = player_animate;
	player_animator.numFrames = 8;
	player_animator.frames = player_frame_data;

	state.score = 0;

	setObject(
		&player, // object
		player_x, // x-pos
		player_y, // y-pos
		0, // sprite start tile
		6, // num tiles
		2, // sprite width
		3, // sprite height
		&player_animator // animator
	);
	// setObject(&enemyOne, enemy_x, 0, 0, 0, 0);
	// setObject(&enemyTwo, enemy_x, 0, 0, 0, 0);

	printf("game\n");
}

void setGameData(){
	// init sprite, bkg, window game data

	set_sprite_data(0, 24, hacker_tiles);
	set_sprite_data(24, 9, fly_tiles);
	set_sprite_data(33, 4, cactus_tiles);
}
