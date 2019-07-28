#include "score.h"

UINT16 scoreCheck;

unsigned char score_map[score_size] = {
	0x30,0x30,0x30,0x30
};

void increaseScore(Backdrop *score){
	if(intervalCheck(&scoreCheck, 100)){
		if(state.score < 9999){
			++state.score;
			updateScoreTiles();
			score->tiles = score_map;
		}
	}
}

UINT8 scoreValueInPos;
UINT16 find;

void updateScoreTiles(){
	find = 10;
	for(i = 0; i < score_size; ++i){
		scoreValueInPos = (state.score % find) / (find / 10);
		score_map[i] = 0x30 + scoreValueInPos;
		find = find * 10;
	}
}

void resetScoreMap(){
	for(i = 0; i < score_size; ++i){
		score_map[i] = 0x30;
	}
}
