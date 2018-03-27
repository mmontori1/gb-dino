#include "game.h"

Object player;
Object enemyOne;
Object enemyTwo;

Animator player_animator;

Dimension player_dimension;
Dimension ground_dimension;

Backdrop ground;

Backdrop *game_bkg[1] = {
	&ground
};

void initGame(){
	ground_dimension.x = 0;
	ground_dimension.y = 16;
	ground_dimension.width = 32;
	ground_dimension.height = 2;

	ground.dimension = &ground_dimension;
	ground.tiles = ground_map;

	player_dimension.x = player_x;
	player_dimension.y = player_y;
	player_dimension.width = 2;
	player_dimension.height = 3;

	player_animator.type = player_animate;
	player_animator.numFrames = 8;
	player_animator.frames = player_frame_data;

	player.startTile = 0;
	player.numTiles = 6;
	player.dimension = &player_dimension;
	player.animator = &player_animator;
}

void setupGame(){
	state.score = 0;
	state.bkg = game_bkg;
	state.num_bkg = 1;
}

void setGameData(){
	// init sprite, bkg, window game data
	set_sprite_data(0, 24, hacker_tiles);
	set_sprite_data(24, 9, fly_tiles);
	set_sprite_data(33, 4, cactus_tiles);

	set_bkg_data(0, 2, ground_tiles);

}
