#include "bullet.h"


bullet::bullet(Vector2 fire_position, Vector2 speed)
{
	this->fire_position = fire_position;
	this->speed = speed;
	active = true;
}
bullet::~bullet()
{

}

void bullet::draw(Vector2 player_object)
{
	if (active)
	{
		DrawCircleV(fire_position + player_object / 400, 20, BLUE);
	}
}
void bullet::update_position()
{
	fire_position += speed;

	if (active)
	{
		if (fire_position.x > GetScreenWidth() + 500 || fire_position.y > GetScreenHeight() + 500 || fire_position.x < 0 || fire_position.y < 0)
		{
			active = false;
		}
	}
}