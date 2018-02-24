#include "input.h"

void checkInput(){
	switch(joypad()) {
		case J_START :
			if(start_button) start_button();
			break;
		case J_SELECT :
			if(select_button) select_button();
			break;
		case J_UP :
			if(up_button) up_button();
			break;
		case J_LEFT :
			if(left_button) left_button();
			break;
		case J_RIGHT :
			if(right_button) right_button();
			break;
		case J_DOWN :
			if(down_button) down_button();
			break;
		case J_A :
			if(a_button) a_button();
			break;
		case J_B :
			if(b_button) b_button();
			break;
	}
}

void setInputs(Action type){
	switch(type) {
		case START :
			printf("START");
			break;
		case GAME :
			printf("GAME");
			break;
		case OVER :
			printf("OVER");
			break;
	}
}

void (*start_button) ();
void (*select_button) ();
void (*up_button) ();
void (*left_button) ();
void (*right_button) ();
void (*down_button) ();
void (*a_button) ();
void (*b_button) ();
