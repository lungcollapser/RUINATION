#pragma once
#include "raylib.h"
#include "raymath.h"

class gun
{
private:
	bool active;
	Vector2 gun_reticle;
	
public:
	gun();
	~gun();
	void draw(Vector2 player_object);
	Vector2 get_gun_reticle();
};