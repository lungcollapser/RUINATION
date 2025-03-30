#include "gun.h"
#include <iostream>

gun::gun(Vector2 position, Vector2 speed)
{
	this->position = position;
	this->speed = speed;
	active = true;
	bullets = 6;
}
gun::~gun()
{
}
void gun::draw()
{
	if (active && bullets > 0)
	{
		DrawCircleV(position, 7, BLUE);
	}
	
}
void gun::updates()
{
	position += speed;

	//fix screenwidth and height. causing bullets to disappear too excessively
	if (active)
	{
		if (position.x > GetScreenWidth() || position.y > GetScreenHeight() || position.x < 0 || position.y < 0)
		{
			active = false;
			std::cout << "deleted";
		}
	}
}
