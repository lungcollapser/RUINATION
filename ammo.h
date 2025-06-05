#pragma once
#include "include.h"

class ammo
{
public: 
	enum ammo_state
	{
		dropped, picked_up
	};

	ammo();
	void draw_clips();
	void draw_ammo(Vector2 player_object);
	Rectangle get_clips_rectangle();
	Vector2 clips_drop;
	Vector2 ammo_drop;
};