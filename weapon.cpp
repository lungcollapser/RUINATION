#include "weapon.h"

player weapon_player;

weapon::weapon()
{
	is_reloading = false;
	weapon_reticle = { 0, 0 };
	mag_bullets = 6;
	bullet_damage = 1;
	bullet_speed = 1000.0;
}
weapon::~weapon()
{

}
void weapon::fire()
{
	bullets.push_back(bullet(Vector2MoveTowards(weapon_player.player_object, weapon_reticle, 1000), Vector2{-6, -6}));
	std::cout << "shoot";
}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}
