#include "state.h"

void updateState(State *state, Action type){
	state->type = type;
	clearInputs();
	
	switch(type){
		case START :
			setupStart(state);
			state->setData = NULL;
			state->updateLogic = NULL;
			break;
		case GAME :
			setupGame(state);
			state->setData = setGameData;
			state->updateLogic = gameLoop;
			break;
		case OVER :
			setupOver(state);
			state->setData = NULL;
			state->updateLogic = NULL;
			break;
	}

	VBL_FLAG_ON;
}
