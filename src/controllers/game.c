#include "game.h"

Animate player_animate[6] = {CONSTANT, CONSTANT, DYNAMIC, DYNAMIC, DYNAMIC, DYNAMIC};

//sprite data, move to data.h sometime???
UINT8 player_midleft_data[8] = {3, 5, 7, 3, 3, 8, 10, 3};
UINT8 player_midright_data[8] = {4, 6, 6, 4, 4, 9, 11, 4};
UINT8 player_botleft_data[8] = {12, 14, 16, 18, 12, 20, 22, 20};
UINT8 player_botright_data[8] = {13, 15, 17, 19, 13, 21, 23, 21};
UINT8 *player_frame_data[4] = {
	&player_midleft_data, 
	&player_midright_data, 
	&player_botleft_data,
	&player_botright_data
};

void setupGame(){
	Animator player_animator;
	player_animator.type = player_animate;
	player_animator.numFrames = 8;
	player_animator.frames = player_frame_data;

	state.score = 0;

	setObject(
		&player, 
		player_x, 
		player_y, 
		0, 
		6, 
		2, 
		3, 
		&player_animator
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
