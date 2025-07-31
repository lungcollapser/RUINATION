#pragma once

#ifndef AMMO_H
#define AMMO_H

#include "include.h"


class ammo
{

public: 
	ammo();
	void draw(Vector2 position);
	void update();
	Rectangle get_rectangle(Vector2 position);
	Vector2 ammo_drop;
	bool ammo_collision;
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

	int ammo_choices_rand;
	int ammo_choices;
};
#endif