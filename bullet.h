#pragma once
#include "include.h"
#include "enemy.h"

class bullet 
{
public:
	bullet(Vector2 fire_position, int bullet_speed);
	~bullet();
	void draw(Vector2 player_position);
	void update_position();
	bool active;
	Vector2 fire_position;
	int bullet_speed;
};