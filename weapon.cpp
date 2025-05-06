#include "weapon.h"

player weapon_player;


weapon::weapon()
{
	is_reloading = false;
	weapon_reticle = { 0, 0 };
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
void weapon::draw(Vector2& player_object)
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
		change_weapon(revolver);
		std::cout << current_weapon;
	}
	if (IsKeyPressed(KEY_TWO))
	{
		change_weapon(repeater);
		std::cout << current_weapon;
	}
}

void weapon::reload()
{
	
}
void weapon::change_weapon(weapon_types new_weapon)
{
	switch (new_weapon)
	{
	case revolver: current_weapon = new_weapon; bullet_amount = 6; bullet_speed = 4000;
		break;
	case repeater: current_weapon = new_weapon; bullet_amount = 12; bullet_speed = 5000;
		break;
	}

}