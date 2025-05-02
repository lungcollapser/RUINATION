#include "weapon.h"

player weapon_player;

weapon::weapon()
{
	is_reloading = false;
	weapon_reticle = { 0, 0 };
	current_weapon = "revolver";
	bullet_amount = 0;
	bullet_speed = 0;

	if (current_weapon == "revolver")
	{
		bullet_speed = 4000;
		bullet_amount = 6;
		reload();
	}
}

weapon::~weapon()
{

}
void weapon::fire()
{
	//Could possibly use later if speed is on Vector2. For now just use given value.
	/*Vector2 direction = {cos(PI / 180), -sin(PI / 180)};
	Vector2 bullet_velocity = Vector2Scale(direction, bullet_speed);*/
	bullets.push_back(bullet(Vector2MoveTowards(weapon_player.player_object, weapon_reticle, 1), bullet_speed));

	if (bullet_amount < 1)
	{
		return;
	}
}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);

}
void weapon::take_input()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{

		fire();
		bullet_amount -= 1;
		std::cout << bullet_amount;
	}

}
void weapon::weapon_attributes()
{

}
void weapon::reload()
{
	if (bullet_amount < 1)
	{
		return;
	}
}