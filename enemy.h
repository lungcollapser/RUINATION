#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "include.h"
#include "weapon.h"

class enemy
{
public:
	enemy();
	~enemy();
	void draw();
	void update(Vector2 &player_object);
	int take_damage(int damage);
	Rectangle get_rectangle();
	Rectangle enemy_rec;
	Vector2 enemy_object, enemy_position;
	float enemy_health, enemy_speed, enemy_radius, bullet_speed;
	bool bullet_collision;
	enum enemy_move_state
	{
		aggro,
		neutral
	};
	enum enemy_health_state
	{
		alive,
		dead
	};
	enemy_move_state current_move_state;
	enemy_health_state current_health_state;

	weapon* enemy_weapon;
};
#endif