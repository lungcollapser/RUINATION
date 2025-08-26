#pragma once

#ifndef AMMO_H
#define AMMO_H

#include "include.h"


class ammo
{

public: 
	ammo();
	void draw(v2 position);
	void update(Rectangle rec1, Rectangle rec2);
	bool collision(Rectangle collision_one, Rectangle collision_two);

	Rectangle get_rectangle(v2 position);
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

	int16 ammo_choices_rand, ammo_choices;
};
#endif