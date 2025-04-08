#include "weapon.h"

player weapon_player;


weapon::weapon()
{
	is_reloading = false;
	bullet_speed = -10;
	weapon_reticle = { 0, 0 };
	bullet_spread = 0;

}
weapon::~weapon()
{

}
void weapon::fire()
{
	float angle_spread;
	if ((int)bullet_spread == 0) angle_spread = angle;
	else angle_spread = angle + (rand() % (int)bullet_spread - bullet_spread / 2);

	Vector2 direction = { cos(angle_spread * PI / 180), -sin(angle_spread * PI / 180) };
	Vector2 bullet_velocity = Vector2Scale(direction, bullet_speed);
	bullets.push_back(bullet(Vector2MoveTowards(weapon_player.player_object, weapon_reticle, 1000), bullet_velocity));
	std::cout << "shoot";
	
}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}