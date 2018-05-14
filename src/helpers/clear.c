#include "clear.h"
#include "gb/gb.h"

#include "loop.h"

void clearBkg(){
	set_bkg_tiles(0, 0, 32, 18, blank_map);
}

void clearSprite(Object *sprite, UINT8 start, UINT8 end){
	for(i = start; i < end; ++i){
		set_sprite_tile(i + sprite->startTile, 0);
	}
}
