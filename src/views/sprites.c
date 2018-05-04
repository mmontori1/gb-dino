#include "sprites.h"

UINT8 i;
UINT8 j;
UINT8 k;
UINT16 spriteTime;

void drawSprites(State *state){
	if(intervalCheck(&spriteTime, 5)){
		Object* curSprite;
		UINT8 curFrame;
		for(i = 0; i < state->numSprites; ++i){
			curSprite = state->sprites[i];
			for(j = 0; j < curSprite->numTiles; ++j){
				curFrame = curSprite->frameCount;
				if(curSprite->frames[j]->numFrames == 1) curFrame = 0;
				set_sprite_tile(j + curSprite->startTile, curSprite->frames[j]->frames[curFrame]);
				move_sprite(
					j + curSprite->startTile, 
					curSprite->dimension->x + 8 * (j % curSprite->dimension->width), 
					curSprite->dimension->y + 8 * (j / curSprite->dimension->width)
				);
			}
			if(++curSprite->frameCount >= curSprite->maxFrames) curSprite->frameCount = 0;
		}
	}
}
