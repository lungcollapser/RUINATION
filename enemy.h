#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include "include.h"

struct enemy
{

	Vector2 enemy_object, enemy_position;
	int16 enemy_health, enemy_speed, enemy_radius, bullet_speed;
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

void draw_player();
void update_player(v2& player_object, float bullet_damage, Rectangle rec1, Rectangle rec2);
int take_damage(int damage);
bool enemy_collision(Rectangle collision_one, Rectangle collision_two);
#endif