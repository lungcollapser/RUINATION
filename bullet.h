#pragma once
#include "include.h"

class bullet
{
private:
	bool active;
	Vector2 position;
	Vector2 bullet_velocity;

public:
	bullet(Vector2 position, Vector2 bullet_velocity);
	~bullet();
	void draw();
	void update_position(Vector2 v);
	void hitbox();
};