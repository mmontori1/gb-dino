#include "sprites.h"

UINT8 i;
UINT8 j;
UINT8 k;

void drawSprites(){
	for(i = 0; i < state.num_sprites; ++i){ //objects
		for(j = 0; j < state.sprites[i]->numTiles; ++j){ //tiles in object
			set_sprite_tile(j + state.sprites[i]->startTile, state.sprites[i]->frames[j]->frames[0]);
			move_sprite(
				j + state.sprites[i]->startTile, 
				state.sprites[i]->dimension->x + 8 * (j % 2), 
				state.sprites[i]->dimension->y + 8 * (j / 2)
			);
		}
	}
}
