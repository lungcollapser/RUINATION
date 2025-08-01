#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "include.h"

class enemy
{
public:
	enemy();
	~enemy();
	void draw();
	void update(Vector2 &player_object, float bullet_damage, Rectangle rec1, Rectangle rec2);
	int take_damage(int damage);
	bool collision(Rectangle collision_one, Rectangle collision_two);

	Rectangle get_rectangle();
	Rectangle enemy_rec;
	Vector2 enemy_object, enemy_position;
	float enemy_health, enemy_speed, enemy_radius, bullet_speed;
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

};
#endif