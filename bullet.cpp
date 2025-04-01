#include "bullet.h"


bullet::bullet()
{
	active = true;
}
bullet::~bullet()
{

}

void bullet::draw()
{
	if (active)
	{
		DrawCircleV(position, 7, BLUE);
	}
}
void bullet::update_position()
{

	Vector2 change_vector = Vector2Scale(velocity, GetFrameTime());
	position = Vector2Add(position, change_vector);
}
void bullet::queue_free()
{
	if (active)
	{
		if (position.x > GetScreenWidth() + 500 || position.y > GetScreenHeight() + 500 || position.x < 0 || position.y < 0)
		{
			active = false;
		}
	}
}