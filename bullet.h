#pragma once
#include "raylib.h"
#include "raymath.h"

class bullet
{
private:
	Vector2 velocity;
	Vector2 position;
	float damage;
	bool active;
public:
	bullet();
	~bullet();
	void draw();
	void update_position();
	void hitbox();
	void queue_free();
};