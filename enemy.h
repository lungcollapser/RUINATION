#pragma once
#include "include.h"
#include "weapon.h"

class enemy
{
public:
	enemy();
	~enemy();
	void draw();
	void update_position();
	void fire(Vector2 &player_object);
	Rectangle get_rectangle();
	Vector2 enemy_object;
	int enemy_health, enemy_speed, bullet_speed;
	std::vector<bullet> enemy_bullets;
	enum enemy_state
	{
		alive = 0, 
		dead = 1
	};
	enemy_state current_state;

};