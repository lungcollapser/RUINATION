#pragma once
#include "include.h"

class enemy
{
public:
	enemy();
	~enemy();
	void draw();
	void update_position();
	Rectangle get_rectangle();
	Vector2 enemy_object;
	int enemy_health, enemy_speed;
	enum enemy_state
	{
		alive = 0, 
		dead = 1
	};
	enemy_state current_state;

};