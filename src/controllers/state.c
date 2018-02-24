#include "state.h"

void updateState(Action type){
	state.type = type;
	clearInputs();
	switch(type){
		case START :
			printf("START\n");
			setupStart();
			break;
		case GAME :
			printf("GAME\n");
			setupGame();
			break;
		case OVER :
			printf("OVER\n");
			setupOver();
			break;
	}
}

void updateLogic(){

}
