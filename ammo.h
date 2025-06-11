#pragma once
#include "include.h"

class ammo
{
public: 
	ammo();
	void draw_clips(Vector2 position);
	void draw_ammo(Vector2 position);
	Rectangle get_clips_rectangle(Vector2 position);
	Rectangle get_ammo_rectangle(Vector2 position);
	enum ammo_state
	{
		dropped = 0,
		picked_up = 1
	};
	ammo_state current_clips_state;
	ammo_state current_ammo_state;
};