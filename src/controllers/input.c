#include "input.h"

void checkInput(State *state){
	switch(joypad()) {
		case J_START :
			if(start_button) (*start_button)(state);
			break;
		case J_SELECT :
			if(select_button) (*select_button)(state);
			break;
		case J_UP :
			if(up_button) (*up_button)(state);
			break;
		case J_LEFT :
			if(left_button) (*left_button)(state);
			break;
		case J_RIGHT :
			if(right_button) (*right_button)(state);
			break;
		case J_DOWN :
			if(down_button) (*down_button)(state);
			break;
		case J_A :
			if(a_button) (*a_button)(state);
			break;
		case J_B :
			if(b_button) (*b_button)(state);
			break;
	}
}

void clearInputs(){
	start_button = NULL;
	select_button = NULL;
	up_button = NULL;
	left_button = NULL;
	right_button = NULL;
	down_button = NULL;
	a_button = NULL;
	b_button = NULL;
}

void (*start_button) (State *);
void (*select_button) (State *);
void (*up_button) (State *);
void (*left_button) (State *);
void (*right_button) (State *);
void (*down_button) (State *);
void (*a_button) (State *);
void (*b_button) (State *);
