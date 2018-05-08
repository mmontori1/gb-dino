#include "sprites.h"

UINT8 i;
UINT8 j;
UINT8 k;
UINT8 xj;
UINT8 yj;
Object* curSprite;
UINT8 curFrame;

void drawSprites(Object **sprites, UINT8 size){
	for(i = 0; i < size; ++i){
		curSprite = sprites[i];
		if(!inFrameX(curSprite->dimension->x)) continue;
		for(j = 0; j < curSprite->numTiles; ++j){
			curFrame = curSprite->frameCount;
			if(curSprite->frames[j]->numFrames == 1) curFrame = 0;
			if(curSprite->dimension->width == 2){
				xj = j & 1;
				yj = j >> 1;
			}
			else if(curSprite->dimension->width == 3){
				if(j < 3){
					xj = j;
					yj = 0;
				}
				else { 
					xj = j - 3;
					yj = 1; 
				}
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

BOOLEAN inFrameX(INT16 x){
	if(x >= enemy_x) return 0;
	if(x < L_OOF){
		return 0;
	}
	return 1;
}
