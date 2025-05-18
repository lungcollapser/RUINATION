#include "bullet.h"

enemy enemy_bullet;

bullet::bullet(Vector2 fire_position, int bullet_speed)
{
	this->fire_position = fire_position;
	this->bullet_speed = bullet_speed;

}
bullet::bullet()
{

}
bullet::~bullet()
{

}

void bullet::draw(Vector2 player_position)
{
	if (active)
	{
		DrawCircleV(fire_position + player_position, 10, BLUE);
		DrawRectangle(fire_position.x + player_position.x, fire_position.y + player_position.y, 30, 20, PURPLE);
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
