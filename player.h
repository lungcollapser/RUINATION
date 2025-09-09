#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "include.h"

struct player
{
	uint16 player_speed;
	v2 player_object;
	
};
extern player player_main;

void init_player();
void free_player();
void draw_player();
void update_player();
Rectangle get_rectangle_player(v2 player_object);
#endif