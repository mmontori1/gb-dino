#include <gb/gb.h>
#include <stdio.h>

void startScreen();
void displaySprite();
void runGame();

//Created with GBTD, exported to .c with options from: 0, to: 0, label: smile
unsigned char smile[] = {
  0x3C,0x3C,0x42,0x42,0x81,0x81,0xA5,0xA5,
  0x81,0x81,0x81,0xA5,0x42,0x5A,0x3C,0x3C
};

void main() {
	startScreen();
}

void startScreen(){
	printf("Welcome to GAMEBOY\nProgramming");
    printf("\nPress Start");
    waitpad(J_START);  // other keys are J_A, J_UP, J_SELECT, etc.
    printf("\nIsn't it easy!");
    displaySprite();
}

void displaySprite(){
	int x = 55; // Our beginning x coord
	int y = 75; // Our beginning y coord
	
	SPRITES_8x8;
	set_sprite_data(0, 0, smile);
	set_sprite_tile(0, 0);
	move_sprite(0, x, y); // Move sprite to our predefined x and y coords

	SHOW_SPRITES;
}

void runGame(){

}



/*
Things to do:
-Start screen
-Dino movement
	-Jump
	-Duck
-Score
-Enemies
	-types of enemies
		-bird
		-cactus
	-movement
	-collision detection
-Game over
-Pause
*/