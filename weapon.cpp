#include "weapon.h"

player player_weapon;

weapon::weapon()
{
	is_reloading = false;
	current_weapon = "revolver"
}
weapon::~weapon()
{

}
void weapon::get_weapon_stats()
{

}
void weapon::handle_input()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && is_reloading == false)
	{
		player_weapon.shoot();
	}

	if (IsKeyPressed(KEY_R) && is_reloading == false)
	{
		is_reloading = true;
	}
}
std::string weapon::get_current_weapon(std::string current_weapon)
{
	return current_weapon;
}