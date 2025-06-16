#include "weapon.h"


weapon::weapon()
{
	weapon_reticle = {0, 0};
	is_reloading = false;
}

weapon::~weapon()
{

}
std::vector<bullet>& weapon::get_bullets(weapon *weapon)
{
	return weapon->bullets;
}
void weapon::fire(Vector2 weapon_reticle, Vector2 &center_position, int bullet_speed)
{
	//Could possibly use later if speed is on Vector2. For now just use given value.
	/*Vector2 direction = {cos(PI / 180), -sin(PI / 180)};
	Vector2 bullet_velocity = Vector2Scale(direction, bullet_speed);*/
	
	bullets.push_back(bullet(Vector2Normalize(Vector2Subtract(weapon_reticle, center_position)), bullet_speed));
	bullet_amount -= 1;

}
void weapon::draw(Vector2 &player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}

void weapon::take_input()
{
	if (bullet_amount == 0)
	{
		current_clips -= 1;
		if (current_clips <= 0)
		{
			bullet_amount = 0;
		}
	}
}

