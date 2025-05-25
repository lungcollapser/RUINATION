#include "bullet.h"

enemy enemy_bullet;

bullet::bullet(Vector2 fire_position, int bullet_speed)
{
	this->fire_position = fire_position;
	this->bullet_speed = bullet_speed;

}
bullet::~bullet()
{

}

void bullet::draw(Vector2 player_position)
{
	if (active)
	{
		DrawCircleV(fire_position, 10, BLUE);
	}
}
void bullet::update_position()
{
	Vector2 change_vector = Vector2Scale(Vector2Normalize(fire_position), bullet_speed * GetFrameTime());
	fire_position = Vector2Add(fire_position, change_vector);

}
void bullet::bullet_hitbox()
{
	
}
