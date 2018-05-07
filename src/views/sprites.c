#include "sprites.h"

UINT8 i;
UINT8 j;
UINT8 k;
UINT16 spriteTime;

void drawSprites(State *state){
	UINT8 xj;
	UINT8 yj;
	if(intervalCheck(&spriteTime, 5)){
		Object* curSprite;
		UINT8 curFrame;
		for(i = 0; i < state->numSprites; ++i){
			curSprite = state->sprites[i];
			for(j = 0; j < curSprite->numTiles; ++j){
				curFrame = curSprite->frameCount;
				if(curSprite->frames[j]->numFrames == 1) curFrame = 0;
				if(curSprite->dimension->width == 2){
					xj = j & 1;
					yj = j >> 1;
				}
				else {
					xj = j % curSprite->dimension->width;
					yj = j / curSprite->dimension->width;
				}
				set_sprite_tile(j + curSprite->startTile, curSprite->frames[j]->frames[curFrame]);
				move_sprite(
					j + curSprite->startTile, 
					curSprite->dimension->x + 8 * xj, 
					curSprite->dimension->y + 8 * yj
				);
			}
			if(++curSprite->frameCount >= curSprite->maxFrames) curSprite->frameCount = 0;
		}
	}
}
