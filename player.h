#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "include.h"

struct player
{
	uint16 player_speed;
	v2 player_object;
	
};
local_persist player* player_main = (player*)malloc(sizeof(player));

void init_p();
void free_p();
void draw_p();
void update_p();
Rectangle get_rectangle(v2 player_object);
#endif