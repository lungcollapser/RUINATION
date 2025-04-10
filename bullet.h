#pragma once
#include "include.h"
#include "weapon.h"

class bullet : weapon
{
private:
	bool active;
	Vector2 fire_position;
	int speed;

public:
	bullet(Vector2 fire_position, int speed);
	~bullet();
	void draw(Vector2 player_object);
	void update_position();
	void hitbox();
};