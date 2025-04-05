#include "bullet.h"


bullet::bullet(Vector2 fire_position, Vector2 speed)
{
	active = true;
	this-> fire_position = fire_position;
	this-> speed = speed;
}
bullet::~bullet()
{

}

void bullet::draw()
{
	if (active)
	{
		DrawCircleV(fire_position, 20, BLUE);
	}
}
void bullet::update_position()
{
	speed += fire_position;
}
void bullet::queue_free()
{
	if (active)
	{
		if (fire_position.x > GetScreenWidth() + 500 || fire_position.y > GetScreenHeight() + 500 || fire_position.x < 0 || fire_position.y < 0)
		{
			active = false;
			std::cout << "deleted";
		}
	}
}