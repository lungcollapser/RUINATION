#pragma once
#include "include.h"

class ammo
{
public: 
	ammo();
	void draw_clips();
	void draw_ammo(Vector2 player_object);
	Vector2 clips_drop;
	Vector2 ammo_drop;
	Rectangle collision;
};