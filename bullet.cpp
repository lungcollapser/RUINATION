#include "bullet.h"


bullet::bullet(Vector2 fire_position, int bullet_speed)
{
	this->fire_position = fire_position;
	this->bullet_speed = bullet_speed;
	active = true;

}
bullet::~bullet()
{

}

void bullet::draw(Vector2 player_position)
{
	if (active)
	{
		DrawCircleV(fire_position + player_position, 20, BLUE);
	}
}
void bullet::update_position()
{
	Vector2 change_vector = Vector2Scale(Vector2Normalize(fire_position), bullet_speed * GetFrameTime());
	fire_position = Vector2Add(fire_position, change_vector);
}