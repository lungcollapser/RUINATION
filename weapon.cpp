#include "weapon.h"

player weapon_player;

weapon::weapon()
{
	weapon_attributes();
	is_reloading = false;
	weapon_reticle = { 0, 0 };
	weapons[1] = "fists";
	weapons[2] = "revolver";
	weapons[3] = "repeater";
	current_weapon = "";
}

weapon::~weapon()
{

}
void weapon::fire()
{
	//Could possibly use later if speed is on Vector2. For now just use given value.
	/*Vector2 direction = {cos(PI / 180), -sin(PI / 180)};
	Vector2 bullet_velocity = Vector2Scale(direction, bullet_speed);*/
	if (bullet_amount > 0)
	{
		bullets.push_back(bullet(Vector2MoveTowards(weapon_player.player_object, weapon_reticle, 1), bullet_speed));

	}

}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);

}
void weapon::take_input()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && bullet_amount > 0)
	{

		fire();
		bullet_amount -= 1;
		std::cout << bullet_amount;
	}
	if (IsKeyPressed(KEY_ONE))
	{
		current_weapon = weapons[1];
		std::cout << current_weapon;
	}
	if (IsKeyPressed(KEY_TWO))
	{
		current_weapon = weapons[2];
		std::cout << current_weapon;
	}
	if (IsKeyPressed(KEY_THREE))
	{
		current_weapon = weapons[3];
		std::cout << current_weapon;
	}
	reload();
}
void weapon::weapon_attributes()
{
	if (current_weapon == weapons[1])
	{
		bullet_speed = 0;
		bullet_amount = 0;
	}
	if (current_weapon == weapons[2])
	{
		bullet_speed = 4000;
		bullet_amount = 6;
	}
	if (current_weapon == weapons[3])
	{
		bullet_speed = 6000;
		bullet_amount = 3;

	}
	
}
void weapon::reload()
{
	if (IsKeyPressed(KEY_R))
	{
		bullet_amount = 6;
	}
}