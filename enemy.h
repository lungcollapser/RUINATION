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


void init_enemy();
void draw_enemy();
void update_enemy(v2 position, uint16 bullet_damage);
int take_damage(uint16 damage);
#endif