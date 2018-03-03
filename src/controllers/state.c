#include "state.h"

void updateState(Action type){
	state.type = type;
	VBL_FLAG_ON;
	clearInputs();
	
	switch(type){
		case START :
			setupStart();
			break;
		case GAME :
			setupGame();
			break;
		case OVER :
			setupOver();
			break;
	}
}

void updateLogic(){

}
