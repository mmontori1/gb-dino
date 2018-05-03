#include "game.h"
#include <stdio.h>

UINT8 i;

Object player;
Object enemyOne;
Object enemyTwo;

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
Dimension e1_dimension;
Dimension e2_dimension;
Dimension ground_dimension;

Backdrop ground;

Backdrop *game_bkg[1] = {
	&ground
};

Object *game_objects[1] = {
	&player
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

	player_topleft_frames.numFrames = 1;
	player_topleft_frames.frames = player_topleft_data;
	player_topright_frames.numFrames = 1;
	player_topright_frames.frames = player_topright_data;
	player_midleft_frames.numFrames = 8;
	player_midleft_frames.frames = player_midleft_data;
	player_midright_frames.numFrames = 8;
	player_midright_frames.frames = player_midright_data;
	player_botleft_frames.numFrames = 8;
	player_botleft_frames.frames = player_botleft_data;
	player_botright_frames.numFrames = 8;
	player_botright_frames.frames = player_botright_data;

	player.startTile = 0;
	player.numTiles = 6;
	player.frameCount = 0;
	player.maxFrames = 8;
	player.dimension = &player_dimension;
	player.frames = player_frames;

	enemyOne.dimension = &e1_dimension;
	enemyTwo.dimension = &e2_dimension;
}

void setupGame(State *state){
	state->score = 0;
	state->bkg = game_bkg;
	state->numBkg = 1;
	state->sprites = game_objects;
	state->numSprites = 1;
}

void gameLoop(){

}

void pickEnemy(Object *enemy){
	UINT8 type = getRand() & 1;
	if(type){
		setCactus(enemy);
	}
	else {
		setFly(enemy);
	}
}

void setCactus(Object *enemy){
	enemy->dimension->x = enemy_x;
	enemy->dimension->y = cactus_y;
	enemy->dimension->width = 2;
	enemy->dimension->height = 2;
}

void setFly(Object *enemy){
	enemy->dimension->x = enemy_x;
	enemy->dimension->y = cactus_y;
	enemy->dimension->width = 3;
	enemy->dimension->height = 2;
}

void setGameData(){
	// init sprite, bkg, window game data
	set_sprite_data(0, 24, hacker_tiles);
	set_sprite_data(24, 9, fly_tiles);
	set_sprite_data(33, 4, cactus_tiles);

	set_bkg_data(0, 2, ground_tiles);

}
