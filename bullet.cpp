#include "bullet.h"


bullet::bullet(Vector2 position, Vector2 bullet_velocity)
{
	this->position = position;
	this->bullet_velocity = bullet_velocity;
	active = true;
}
bullet::~bullet()
{

}

void bullet::draw()
{
	if (active)
	{
		DrawCircleV(position, 20, BLUE);
	}
}
void bullet::update_position(Vector2 v)
{
	position += v;

	if (active)
	{
		if (position.x > GetScreenWidth() + 500 || position.y > GetScreenHeight() + 500 || position.x < 0 || position.y < 0)
		{
			active = false;
		}
	}
}