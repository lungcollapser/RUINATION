#pragma once

#ifndef BULLET_H
#define BULLET_H

#include "include.h"

class bullet 
{
public:
	bullet();
	bullet(v2 fire_position, int bullet_speed);
	~bullet();
	void draw(v2 position);
	void update(int screen_x, int screen_y, v2 player_object, Rectangle player_collision);
	bool collision(Rectangle collision_one, Rectangle collision_two);
	Rectangle get_rectangle(v2 player_position);
	bool active;
	v2 fire_position;
	int16 bullet_speed, bullet_radius;

};
#endif