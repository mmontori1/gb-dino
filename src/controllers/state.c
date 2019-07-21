#include "state.h"

void updateState(Action type, UINT8 numSpriteTiles){
	state.type = type;
	clearInputs();
	clearAll(numSpriteTiles);
	
	switch(type){
		case START :
			setupStart();
			state.setData = NULL;
			state.updateLogic = NULL;
			break;
		case GAME :
			setupGame();
			state.setData = setGameData;
			state.updateLogic = gameLoop;
			break;
		case OVER :
			setupOver();
			state.setData = NULL;
			state.updateLogic = NULL;
			break;
	}

	VBL_FLAG_ON;
}
