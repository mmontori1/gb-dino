#include "game.h"
#include <stdio.h>

UINT8 i;
UINT8 speed;

INT8 jumpCount;
BOOLEAN isJump;
BOOLEAN isDrop;
BOOLEAN isTank;
BOOLEAN backToHacker;
BOOLEAN oneSwitch;
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

Frames tank_topleft_frames;
Frames tank_topright_frames;
Frames tank_botleft_frames;
Frames tank_botright_frames;
Frames *tank_frames[4] = {
	&tank_topleft_frames,
	&tank_topright_frames,
	&tank_botleft_frames,
	&tank_botright_frames
};

Frames cactus_topleft_frames;
Frames cactus_topright_frames;
Frames cactus_botleft_frames;
Frames cactus_botright_frames;
Frames *cactus_frames[4] = {
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

#define JUMP_ARR_LENGTH 7
UINT8 jump_arr[JUMP_ARR_LENGTH] = {6, 5, 4, 3, 2, 1, 0};

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
	player_midleft_frames.numFrames = player_max_frames;
	player_midleft_frames.frames = player_midleft_data;
	player_midright_frames.numFrames = player_max_frames;
	player_midright_frames.frames = player_midright_data;
	player_botleft_frames.numFrames = player_max_frames;
	player_botleft_frames.frames = player_botleft_data;
	player_botright_frames.numFrames = player_max_frames;
	player_botright_frames.frames = player_botright_data;

	tank_topleft_frames.numFrames = 1;
	tank_topleft_frames.frames = tank_topleft_data;
	tank_topright_frames.numFrames = 1;
	tank_topright_frames.frames = tank_topright_data;
	tank_botleft_frames.numFrames = tank_max_frames;
	tank_botleft_frames.frames = tank_botleft_data;
	tank_botright_frames.numFrames = tank_max_frames;
	tank_botright_frames.frames = tank_botright_data;

	fly_topleft_frames.numFrames = 1;
	fly_topleft_frames.frames = fly_topleft_data;
	fly_topmid_frames.numFrames = fly_max_frames;
	fly_topmid_frames.frames = fly_topmid_data;
	fly_topright_frames.numFrames = fly_max_frames;
	fly_topright_frames.frames = fly_topright_data;
	fly_botleft_frames.numFrames = fly_max_frames;
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
	player.maxFrames = player_max_frames;
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
}

void setupGame(State *state){
	speed = 3;

	isJump = 0;
	isDrop = 0;
	isTank = 0;
	oneSwitch = 1;
	backToHacker = 0;
	jumpCount = 0;
	goingUp = 1;

	a_button = beginJump;
	b_button = switchTank;
	up_button = beginJump;
	down_button = playerDown;

	state->score = 0;
	state->bkg = game_bkg;
	state->numBkg = 1;
	state->sprites = game_objects;
	state->numSprites = 3;

	setHacker();
	pickEnemy(&enemyOne);
	pickEnemy(&enemyTwo);
}

void gameLoop(){
	enemyMovement();
	jumpCheck();
	scroll_bkg(1, 0);
	turnSwitchBack();
	checkDimensions();
}

void enemyMovement() {
	if(enemyOne.dimension->x != enemy_x){
		enemyOne.dimension->x -= speed;
	}
	else if(enemyTwo.dimension->x != enemy_x){
		enemyTwo.dimension->x -= speed;
	}
	else if(enemyOne.dimension->x == enemy_x && enemyTwo.dimension->x == enemy_x){
		if(getRand() & 1){
			pickEnemy(&enemyOne);
			enemyOne.dimension->x -= speed;
		}
		else {
			pickEnemy(&enemyTwo);
			enemyTwo.dimension->x -= speed;
		}
	}
}

void jumpCheck(){
	if(isJump) {
		player.frameCount = 10;
		if(goingUp && !isDrop) {
			player.dimension->y -= jump_arr[jumpCount];
			++jumpCount;
			if(jumpCount == JUMP_ARR_LENGTH){
				jumpCount = JUMP_ARR_LENGTH - 1;
				goingUp = 0;
			}
		}
		else if(isDrop){
			player.dimension->y += 8;
			if(player.dimension->y > player_y){
				player.dimension->y = player_y;
				jumpEnd();
			}
		}
		else {
			player.dimension->y += jump_arr[jumpCount];
			--jumpCount;
			if(jumpCount < 0){
				jumpEnd();
			}
		}
	}
}

void jumpEnd(){
	isJump = 0;
	isDrop = 0;
	jumpCount = 0;
	goingUp = 1;
	player.frameCount = 0;
}

void beginJump(){
	isJump = 1;
	isDrop = 0;
	if(isTank){
		setHacker();
		isTank = 0;
	}
}

void switchTank(){
	if(!isJump && oneSwitch){
		if(!isTank){
			setTank();
			if(B_PRESS) oneSwitch = 0;
		}
		else{
			setHacker();
			if(B_PRESS) oneSwitch = 0;
		}
	}
}

void turnSwitchBack(){
	if(!(joypad() & J_B)) oneSwitch = 1;
}

void playerDown(){
	isDrop = 1;
}

void checkDimensions(){
	checkX(&enemyOne.dimension->x);
	checkX(&enemyTwo.dimension->x);
	checkPlayerY(&player.dimension->y);
}

void checkX(INT16 *val){
	if(*val < L_OOF) *val = enemy_x;
	if(*val > R_OOF) *val = enemy_x;
}

void checkPlayerY(UINT8 *val){
	if(isTank){
		if(*val > player_y + 8) *val = player_y + 8;
	}
	else {
		if(*val > player_y) *val = player_y;
	}
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

void setHacker(){
	clearSprite(&player, 4, 6);
	player.numTiles = 6;
	player.frameCount = 0;
	player.maxFrames = player_max_frames;
	player.dimension->x = player_x;
	player.dimension->y = player_y;
	player.dimension->width = 2;
	player.dimension->height = 3;
	player.frames = player_frames;
	isTank = 0;
}

void setTank(){
	clearSprite(&player, 4, 6);
	player.numTiles = 4;
	player.frameCount = 0;
	player.maxFrames = tank_max_frames;
	player.dimension->x = player_x;
	player.dimension->y = player_y + 8;
	player.dimension->width = 2;
	player.dimension->height = 2;
	player.frames = tank_frames;

	isTank = 1;
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
	enemy->maxFrames = fly_max_frames;
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
	set_sprite_data(37, 8, tank_tiles);

	set_bkg_data(0, 2, ground_tiles);

}
