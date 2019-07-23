#include "state.h"

void updateState(Action type){
	state.type = type;
	clearInputs();
	clearAll();

	switch(type){
		case START :
			setupStart();
			state.setData = NULL;
			state.updateLogic = NULL;
			break;
		case GAME :
			setupGame();
			state.setData = NULL;
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
