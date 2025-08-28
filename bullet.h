#pragma once

#ifndef BULLET_H
#define BULLET_H

#include "include.h"

#define MAX_BULLETS 50

struct bullet 
{
	bool active;
	v2 fire_position;
	v2 velocity;
	v2 speed;

};

extern bullet bullets[MAX_BULLETS];

void init_b(v2 player_object);
void free_b();
void draw_b(v2 position);
void update_b(v2 weapon_reticle, v2 center_position);
bool bullet_collision(Rectangle collision_one, Rectangle collision_two);
Rectangle get_rectangle_bullet(v2 player_position);
#endif