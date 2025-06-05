#include "bullet.h"

enemy enemy_bullet;

bullet::bullet()
{

}
bullet::bullet(Vector2 fire_position, int bullet_speed)
{
	this->fire_position = fire_position;
	this->bullet_speed = bullet_speed;
	active = false;
}
bullet::~bullet()
{

}

void bullet::draw(Vector2 player_position)
{
	if (active)
	{
		DrawCircleV(fire_position + player_position, 10, BLUE);
		DrawRectangleLinesEx(get_rectangle(), 3, RED);
	}
}
void bullet::update_position(int screen_x, int screen_y)
{
	Vector2 change_vector = Vector2Scale(Vector2Normalize(fire_position), bullet_speed * GetFrameTime());
	fire_position = Vector2Add(fire_position, change_vector);

	if (fire_position.x > screen_x || fire_position.y > screen_y)
	{
		active = false;
	}
	else
	{
		active = true;
	}

}
Rectangle bullet::get_rectangle()
{
	return Rectangle{ fire_position.x, fire_position.y, 15, 15 };
}
