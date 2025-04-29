#pragma once
#include "include.h"

class enemy
{
public:
	enemy();
	~enemy();
	void draw();
	void update_position();
	Vector2 enemy_object;
	int enemy_health;
	int enemy_speed;
	int enemy_state;
};