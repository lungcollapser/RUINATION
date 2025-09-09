#pragma once

#ifndef AMMO_H
#define AMMO_H
#define MAX_BULLETS 50

#include "include.h"
#include "collision_comp.h"

struct ammo_system
{

	v2 ammo_drop;

	enum ammo_type
	{
		bullets = 0,
		clips = 1
	};
	enum ammo_state
	{
		dropped = 0,
		picked_up = 1
	};
	ammo_type current_ammo_type;
	ammo_state current_ammo_state;

	uint16 ammo_choices_rand, ammo_choices;
};

struct bullet
{
	bool active;
	v2 fire_position;
	v2 speed;
	uint16 max_bullets_per_weapon;
	uint16 bullet_damage;
	uint16 bullet_amount;
	bool weapon_lock;

};

extern bullet bullets[MAX_BULLETS];


void init_ammo(v2 position);
void free_ammo();
void draw_ammo(v2 position);
void update_ammo(v2 position_one, v2 position_two);

Rectangle get_rectangle(v2 position);
#endif