#pragma once
#include "raylib.h"
#include "raymath.h"

class gun
{
private:
	bool active;
public:
	gun(Vector2 position, Vector2 speed);
	~gun();
	void updates();
	void draw();
	
	Vector2 position;
	Vector2 speed;
};