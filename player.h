#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "include.h"

struct player
{
	uint16 player_speed;
	v2 player_object;	
};

void init_player(player *player);
void free_player(player player);
void draw_player(player *player);
void update_player(player *player);
Rectangle get_rectangle_player(v2 player_object);
#endif