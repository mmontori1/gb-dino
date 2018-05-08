#include "game.h"
#include <stdio.h>

UINT8 i;
UINT16 gameTime;
UINT8 rate;
UINT8 speed;

INT8 jumpCount;
BOOLEAN isJump;
UINT8 goingUp;

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

Frames fly_topleft_frames;
Frames fly_topmid_frames;
Frames fly_topright_frames;
Frames fly_botleft_frames;
Frames fly_botmid_frames;
Frames fly_botright_frames;
Frames *fly_frames[6] = {
	&fly_topleft_frames,
	&fly_topmid_frames,
	&fly_topright_frames,
	&fly_botleft_frames,
	&fly_botmid_frames,
	&fly_botright_frames
};


Frames cactus_topleft_frames;
Frames cactus_topright_frames;
Frames cactus_botleft_frames;
Frames cactus_botright_frames;
Frames *cactus_frames[6] = {
	&cactus_topleft_frames,
	&cactus_topright_frames,
	&cactus_botleft_frames,
	&cactus_botright_frames
};

Dimension player_dimension;
Dimension fly_dimension;
Dimension cactus_dimension;
Dimension e1_dimension;
Dimension e2_dimension;
Dimension ground_dimension;

Backdrop ground;

Backdrop *game_bkg[1] = {
	&ground
};

Object *game_objects[3] = {
	&player,
	&enemyOne,
	&enemyTwo
};

const UINT8 JUMP_ARR_LENGTH = 7;
UINT8 jump_arr[7] = {6, 5, 4, 3, 2, 1, 0};

void initGame(){
	rate = 0;
	speed = 3;

	isJump = 0;
	jumpCount = 0;
	goingUp = 1;

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

	fly_topleft_frames.numFrames = 1;
	fly_topleft_frames.frames = fly_topleft_data;
	fly_topmid_frames.numFrames = 4;
	fly_topmid_frames.frames = fly_topmid_data;
	fly_topright_frames.numFrames = 4;
	fly_topright_frames.frames = fly_topright_data;
	fly_botleft_frames.numFrames = 4;
	fly_botleft_frames.frames = fly_botleft_data;
	fly_botmid_frames.numFrames = 1;
	fly_botmid_frames.frames = fly_botmid_data;
	fly_botright_frames.numFrames = 1;
	fly_botright_frames.frames = fly_botright_data;

	cactus_topleft_frames.numFrames = 1;
	cactus_topleft_frames.frames = cactus_topleft_data;
	cactus_topright_frames.numFrames = 1;
	cactus_topright_frames.frames = cactus_topright_data;
	cactus_botleft_frames.numFrames = 1;
	cactus_botleft_frames.frames = cactus_botleft_data;
	cactus_botright_frames.numFrames = 1;
	cactus_botright_frames.frames = cactus_botright_data;

	player.startTile = 0;
	player.numTiles = 6;
	player.frameCount = 0;
	player.maxFrames = 8;
	player.dimension = &player_dimension;
	player.frames = player_frames;

	fly_dimension.x = enemy_x;
	fly_dimension.y = fly_y;
	fly_dimension.width = 3;
	fly_dimension.height = 2;

	cactus_dimension.x = enemy_x;
	cactus_dimension.y = cactus_y;
	cactus_dimension.width = 2;
	cactus_dimension.height = 2;

	enemyOne.startTile = 6;
	enemyOne.dimension = &e1_dimension;
	enemyTwo.startTile = 12;
	enemyTwo.dimension = &e2_dimension;

	// pickEnemy(&enemyOne);
	// pickEnemy(&enemyTwo);
	setFly(&enemyOne);
	setCactus(&enemyTwo);
}

void setupGame(State *state){
	a_button = beginJump;
	state->score = 0;
	state->bkg = game_bkg;
	state->numBkg = 1;
	state->sprites = game_objects;
	state->numSprites = 3;
}

void gameLoop(){
	// if(intervalCheck(&gameTime, rate)){
		enemyMovement();
		jumpCheck();
		scroll_bkg(1,0);
	// }
}

void enemyMovement() {
	// if(enemyOne.dimension->x != enemy_x){
		enemyOne.dimension->x -= speed;
	// }
	// else if(enemyTwo.dimension->x != enemy_x){
		enemyTwo.dimension->x -= speed;
	// }
	// else if(enemyOne.dimension->x == enemy_x && enemyTwo.dimension->x == enemy_x){
	// 	if(getRand() & 1){
	// 		pickEnemy(&enemyOne);
	// 		enemyOne.dimension->x -= speed;
	// 	}
	// 	else {
	// 		pickEnemy(&enemyTwo);
	// 		enemyTwo.dimension->x -= speed;
	// 	}
	// }
	checkX(enemyOne.dimension->x);
	checkX(enemyTwo.dimension->x);
		
}

void jumpCheck(){
	if(isJump) {
		player.frameCount = 5;
		if(goingUp) {
			player.dimension->y -= jump_arr[jumpCount];
			++jumpCount;
			if(jumpCount == JUMP_ARR_LENGTH){
				jumpCount = JUMP_ARR_LENGTH - 1;
				goingUp = 0;
			}
		}
		else {
			player.dimension->y += jump_arr[jumpCount];
			--jumpCount;
			if(jumpCount < 0){
				isJump = 0;
				jumpCount = 0;
				goingUp = 1;
				player.frameCount = 0;
			}
		}
	}
}

void beginJump(State *state){
	state->score += 0;
	isJump = 1;
}

void checkX(INT8 *val){
	if(*val < 0) *val = 248;
	if(*val > 248) *val = enemy_x;
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
	enemy->numTiles = 4;
	enemy->frameCount = 0;
	enemy->maxFrames = 1;
	enemy->dimension->x = cactus_dimension.x;
	enemy->dimension->y = cactus_dimension.y;
	enemy->dimension->width = cactus_dimension.width;
	enemy->dimension->height = cactus_dimension.height;
	enemy->frames = cactus_frames;
}

void setFly(Object *enemy){
	enemy->numTiles = 6;
	enemy->frameCount = 0;
	enemy->maxFrames = 4;
	enemy->dimension->x = fly_dimension.x;
	enemy->dimension->y = fly_dimension.y;
	enemy->dimension->width = fly_dimension.width;
	enemy->dimension->height = fly_dimension.height;
	enemy->frames = fly_frames;
}

void setGameData(){
	// init sprite, bkg, window game data
	set_sprite_data(0, 24, hacker_tiles);
	set_sprite_data(24, 9, fly_tiles);
	set_sprite_data(33, 4, cactus_tiles);

	set_bkg_data(0, 2, ground_tiles);

}
