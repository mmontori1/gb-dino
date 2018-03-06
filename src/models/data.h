#ifndef DATA_H
#define DATA_H

#include "object.h"

//background tiles
extern const unsigned char ground_tiles[];

//background map
extern const unsigned char ground_map[];
extern const unsigned char blank_map[];

//sprite tiles
extern const unsigned char hacker_tiles[];
extern const unsigned char fly_tiles[];
extern const unsigned char cactus_tiles[];

//animate by type arrays
extern const Animate player_animate[6];

//animator frame data
extern const UINT8 player_midleft_data[8];
extern const UINT8 player_midright_data[8];
extern const UINT8 player_botleft_data[8];
extern const UINT8 player_botright_data[8];
extern const UINT8 *player_frame_data[4];


#endif
