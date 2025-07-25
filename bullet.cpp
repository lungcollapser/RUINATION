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

void bullet::draw(Vector2& position)
{

	if (active)
	{
		DrawCircleV(fire_position + position, bullet_radius, BLUE);
		
	}
	
}
void bullet::update(int screen_x, int screen_y, int bullet_amount, Vector2 center_position)
{
	//This doesn't work. need to delete bullet when it exits screen.
	if (fire_position.x >= screen_x && fire_position.y >= screen_y)
	{
		active = false;
		std::cout << "inactive";
	}

	Vector2 change_vector = Vector2Scale(Vector2Normalize(fire_position), bullet_speed * GetFrameTime());
	fire_position = Vector2Add(fire_position, change_vector);

	

	
}
Rectangle bullet::get_rectangle(Vector2 position)
{
	return Rectangle{ fire_position.x + position.x, fire_position.y + position.y, 15, 15 };
}
