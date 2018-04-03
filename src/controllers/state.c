#include "state.h"

void updateState(State *state, Action type){
	state->type = type;
	clearInputs();
	
	switch(type){
		case START :
			setupStart(state);
			state->setData = NULL;
			break;
		case GAME :
			setupGame(state);
			state->setData = setGameData;
			break;
		case OVER :
			setupOver(state);
			state->setData = NULL;
			break;
	}

	VBL_FLAG_ON;
}

void updateLogic(){

}
