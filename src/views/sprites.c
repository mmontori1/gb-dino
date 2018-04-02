#include "sprites.h"

UINT8 i;
UINT8 j;
UINT8 k;

void drawSprites(){
	for(i = 0; i < state.num_sprites; ++i){ //objects
		for(j = 0; j < state.sprites[i]->numTiles; ++j){ //tiles in object
			for(k = 0; k < state.sprites[i]->frames[j]->numFrames; ++k){
				printf("%d ", state.sprites[i]->frames[j]->frames[k]);
			}
			printf("\n");
		}
	}
}
