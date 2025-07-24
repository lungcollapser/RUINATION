#include "weapon.h"


weapon::weapon()
{
	weapon_reticle = {0, 0};
	center_position = { 0, 0 };
	
}

weapon::~weapon()
{

}

void weapon::fire(Vector2 &weapon_reticle, Vector2 &center_position, int bullet_speed)
{
	
	bullets = get_bullets();
	bullet_amount -= 1;
	
}
void weapon::draw(Vector2 &player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}
std::unique_ptr<bullet> weapon::get_bullets()
{
	return std::unique_ptr<bullet>(new bullet(Vector2Normalize(Vector2Subtract(weapon_reticle, center_position)), bullet_speed));
}


