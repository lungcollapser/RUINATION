#include "weapon.h"

player weapon_player;

weapon::weapon()
{
	is_reloading = false;
}
weapon::~weapon()
{

}
void weapon::fire()
{
	Vector2 direction = { weapon_player.player_object - weapon_reticle };
	Vector2 weapon_bullet_speed = Vector2Scale(direction, bullet_speed);
	bullets.push_back(bullet({ weapon_player.player_object - weapon_reticle }, weapon_bullet_speed));
	std::cout << "shoot";
	
}
