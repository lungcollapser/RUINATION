#pragma once
#include "include.h"

class bullet
{
private:
	bool active;
	Vector2 fire_position;
	Vector2 speed;

public:
	bullet(Vector2 fire_position, Vector2 speed);
	~bullet();
	void draw();
	void update_position();
	void hitbox();
	void queue_free();
};