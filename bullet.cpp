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
		DrawCircleV(fire_position, 20, BLUE);
	}
}
void bullet::update_position()
{
	Vector2 changeVector = Vector2Scale(speed, GetFrameTime());
	position = Vector2Add(position, changeVector);
	currentRange += Vector2Length(changeVector);
	
}