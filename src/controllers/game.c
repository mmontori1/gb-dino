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

void setupGame(){
	// int i, j, k;
	state.score = 0;

	ground_dimension.x = 0;
	ground_dimension.y = 16;
	ground_dimension.width = 32;
	ground_dimension.height = 2;

	ground.dimension = &ground_dimension;
	ground.tiles = ground_map;
	// printf("%d\n", &ground_map);

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

	state.bkg = game_bkg;
	state.num_bkg = 1;

	// printf("%d\n", state.bkg[0]->tiles);
	/*
	k = 0;
	for(i = 0; i < player.numTiles; ++i){
		if(player.animator->type[i] == DYNAMIC){
			for(j = 0; j < player.animator->numFrames; ++j){
				printf("%d ", player.animator->frames[i - k][j]);
			}
			printf("\n");
		} else {
			++k;
		}
	}
	printf("%d %d %d %d\n", player.dimension->x, player.dimension->y, player.dimension->width, player.dimension->height);
	*/
	// printf("game\n");
}

void setGameData(){
	// init sprite, bkg, window game data
	set_sprite_data(0, 24, hacker_tiles);
	set_sprite_data(24, 9, fly_tiles);
	set_sprite_data(33, 4, cactus_tiles);

	set_bkg_data(0, 2, ground_tiles);

}
