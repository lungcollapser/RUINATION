#include "bullet.h"


bullet::bullet(Vector2 fire_position, int speed)
{
	this->fire_position = fire_position;
	this->speed = speed;
	active = true;

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
	Vector2 change_vector = Vector2Scale(Vector2Normalize(fire_position), speed * GetFrameTime());
	fire_position = Vector2Add(fire_position, change_vector);
	
}