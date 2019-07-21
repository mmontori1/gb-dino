#ifndef DATA_H
#define DATA_H

#include "object.h"

//background/window tiles
extern const unsigned char ground_tiles[];
extern const unsigned char hud_tiles[];

//background/window map
extern const unsigned char ground_map[];
extern const unsigned char hud_map[];
extern const unsigned char hud_edges_map[];
extern const unsigned char hud_sides_map[];
extern const unsigned char game_over_map[];
extern const unsigned char blank_map[];

//sprite tiles
extern const unsigned char hacker_tiles[];
extern const unsigned char tank_tiles[];
extern const unsigned char fly_tiles[];
extern const unsigned char cactus_tiles[];

//animator frame data
#define player_max_frames 16
extern const UINT8 player_topleft_data[1];
extern const UINT8 player_topright_data[1];
extern const UINT8 player_midleft_data[player_max_frames];
extern const UINT8 player_midright_data[player_max_frames];
extern const UINT8 player_botleft_data[player_max_frames];
extern const UINT8 player_botright_data[player_max_frames];

#define tank_max_frames 12
extern const UINT8 tank_topleft_data[1];
extern const UINT8 tank_topright_data[1];
extern const UINT8 tank_botleft_data[tank_max_frames];
extern const UINT8 tank_botright_data[tank_max_frames];

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
