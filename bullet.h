#pragma once
#include "include.h"

class bullet 
{
public:
	bullet();
	bullet(Vector2 fire_position, int bullet_speed);
	~bullet();
	void draw(Vector2 player_position);
	void update_position(int screen_x, int screen_y);
	Rectangle get_rectangle(Vector2 player_position);
	bool active;
	Vector2 fire_position;
	int bullet_speed;
};