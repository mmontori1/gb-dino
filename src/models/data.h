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

//animator frame data
#define player_max_frames 8
extern const UINT8 player_topleft_data[1];
extern const UINT8 player_topright_data[1];
extern const UINT8 player_midleft_data[player_max_frames];
extern const UINT8 player_midright_data[player_max_frames];
extern const UINT8 player_botleft_data[player_max_frames];
extern const UINT8 player_botright_data[player_max_frames];

#define fly_max_frames 4
extern const UINT8 fly_topleft_data[1];
extern const UINT8 fly_topmid_data[fly_max_frames];
extern const UINT8 fly_topright_data[fly_max_frames];
extern const UINT8 fly_botleft_data[fly_max_frames];
extern const UINT8 fly_botmid_data[1];
extern const UINT8 fly_botright_data[1];

extern const UINT8 cactus_topleft_data[1];
extern const UINT8 cactus_topright_data[1];
extern const UINT8 cactus_botleft_data[1];
extern const UINT8 cactus_botright_data[1];

#endif
