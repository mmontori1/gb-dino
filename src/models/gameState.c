#include "gameState.h"
#include "../controllers/input.h"

State state;

void setState(Action type){
	state.type = type;
	setInputs(type);
}
