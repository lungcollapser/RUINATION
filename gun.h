#pragma once
#include "raylib.h"
#include "raymath.h"

class gun
{
public:
	gun(Vector2 position, Vector2 speed);
	void updates();
	void draw();
	
	Vector2 position;
	Vector2 speed;
	bool active;

};