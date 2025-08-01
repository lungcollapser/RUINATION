#include "bullet.h"


bullet::bullet()
{

}
bullet::bullet(Vector2 fire_position, int bullet_speed)
{
	this->fire_position = fire_position;
	this->bullet_speed = bullet_speed;
	bullet_radius = 10;
	active = true;

}
bullet::~bullet()
{

}

void bullet::draw(Vector2 position)
{

	if (active)
	{
		DrawCircleV(fire_position + position, bullet_radius, BLUE);
	}
	
}
bool bullet::collision(Rectangle collision_one, Rectangle collision_two)
{
	if (CheckCollisionRecs(collision_one, collision_two))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void bullet::update(int screen_x, int screen_y, Vector2 player_object, Rectangle player_collision)
{
	//This doesn't work. need to delete bullet when it exits screen.

	bool bullet_player = collision(get_rectangle(player_object), player_collision);

	if (fire_position.x >= screen_x && fire_position.y >= screen_y || bullet_player)
	{
		active = false;
	}

	Vector2 change_vector = Vector2Scale(Vector2Normalize(fire_position), bullet_speed * GetFrameTime());
	fire_position = Vector2Add(fire_position, change_vector);


}


Rectangle bullet::get_rectangle(Vector2 position)
{
	return Rectangle{ fire_position.x + position.x, fire_position.y + position.y, 15, 15 };
}
