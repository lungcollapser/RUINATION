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
local_persist player* player_main;

void init_p(player* player_init);
void free_p(player* player);
void draw_p(player* player);
void update_p(player* player);
Rectangle get_rectangle(v2 player_object);
#endif