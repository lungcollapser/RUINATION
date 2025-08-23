#pragma once

#ifndef BULLET_H
#define BULLET_H

#include "include.h"

struct bullet 
{
	bool active;
	v2 fire_position;
	uint16 bullet_speed, bullet_radius;

};
extern bullet* bullet_main;

void init_b(v2 player_object);
void free_b();
void draw_b(v2 position, uint16 bullet_amount);
void update_b(v2 weapon_reticle, v2 center_position, uint16 bullet_amount);
bool bullet_collision(Rectangle collision_one, Rectangle collision_two);
Rectangle get_rectangle_bullet(v2 player_position);
#endif