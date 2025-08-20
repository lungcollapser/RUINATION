#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "include.h"
#include "revolver.h"
#include "repeater.h"


struct player
{
	uint16 player_speed;
	v2 player_object;
	
};
void init_p(player* player_main);
void free_p(player* player_main);
void draw_p(player* player_main);
void update_p(player* player_main);
Rectangle get_rectangle(v2 player_object);
#endif