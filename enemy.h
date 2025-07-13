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
	Vector2 enemy_object, enemy_position;
	int enemy_health, enemy_speed, enemy_radius, bullet_speed;
	enum enemy_state
	{
		aggro,
		neutral,
		alive, 
		dead
	};
	enemy_state current_state;
};
#endif