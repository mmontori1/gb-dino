#include "score.h"

#include "../helpers/mtime.h"
#include "../models/gameState.h"

UINT16 scoreCheck;

void increaseScore(){
	if(intervalCheck(&scoreCheck, 15)){
		++state.score;
	}
}
