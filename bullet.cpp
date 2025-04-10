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

void bullet::draw(Vector2 player_object)
{
	if (active)
	{
		DrawCircleV(fire_position, 20, BLUE);
	}
}
void bullet::update_position()
{
	fire_position.x += weapon_reticle.x * speed;
	fire_position.y += weapon_reticle.y * speed;
	
}