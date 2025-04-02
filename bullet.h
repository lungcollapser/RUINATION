#pragma once
#include "raylib.h"
#include "raymath.h"

class bullet
{
private:
	float damage;
	bool active;
	Vector2 position;
	Vector2 bullet_velocity;

public:
	bullet(Vector2 position, Vector2 bullet_velocity);
	~bullet();
	void draw();
	void update_position(Vector2 v);
	void hitbox();
	void queue_free();
};