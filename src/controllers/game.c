#include "game.h"

Object player;
Object enemyOne;
Object enemyTwo;

Animator player_animator;

Frames player_topleft_frames;
Frames player_topright_frames;
Frames player_midleft_frames;
Frames player_midright_frames;
Frames player_botleft_frames;
Frames player_botright_frames;
Frames *player_frames[6] = {
	&player_topleft_frames,
	&player_topright_frames,
	&player_midleft_frames,
	&player_midright_frames,
	&player_botleft_frames,
	&player_botright_frames
};

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

	initFrames(&player_topleft_frames, 1, player_topleft_data);
	initFrames(&player_topright_frames, 1, player_topright_data);
	initFrames(&player_midleft_frames, 8, player_midleft_data);
	initFrames(&player_midright_frames, 8, player_midright_data);
	initFrames(&player_botleft_frames, 8, player_botleft_data);
	initFrames(&player_botright_frames, 8, player_botright_data);

	player.startTile = 0;
	player.numTiles = 6;
	player.dimension = &player_dimension;
	player.frames = player_frames;
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
