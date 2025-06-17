#pragma once
#include "include.h"
#include "weapon.h"

class enemy
{
public:
	enemy();
	~enemy();
	void draw();
	void update_position(Vector2 player_object);
	void fire(Vector2 &player_object, Vector2 center_position);
	Rectangle get_rectangle();
	weapon* enemy_weapon;
	Vector2 enemy_object;
	Vector2 enemy_position;

	int enemy_health, enemy_speed, bullet_speed;
	enum enemy_state
	{
		alive = 0, 
		dead = 1
	};
	enemy_state current_state;
	std::vector<bullet>& get_bullets();


};