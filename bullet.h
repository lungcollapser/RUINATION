#pragma once
#include "include.h"

class bullet 
{
private:
	bool active;
	Vector2 fire_position;
	int speed;

public:
	bullet(Vector2 fire_position, int speed);
	~bullet();
	void draw();
	void update_position();
};