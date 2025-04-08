#include "weapon.h"

player weapon_player;


weapon::weapon()
{
	is_reloading = false;
	bullet_speed = 10;
	weapon_reticle = { 0, 0 };

}
weapon::~weapon()
{

}
void weapon::fire()
{
	
	bullets.push_back(bullet({weapon_player.player_object}, Vector2{-1, -1}));
	std::cout << "shoot";
	
}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}