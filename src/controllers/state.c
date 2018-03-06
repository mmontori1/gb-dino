#include "state.h"

void updateState(Action type){
	state.type = type;
	clearInputs();
	
	switch(type){
		case START :
			setupStart();
			state.setData = NULL;
			break;
		case GAME :
			setupGame();
			state.setData = setGameData;
			break;
		case OVER :
			setupOver();
			state.setData = NULL;
			break;
	}

	VBL_FLAG_ON;
}

void updateLogic(){

}
