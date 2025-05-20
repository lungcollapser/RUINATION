#include "weapon.h"

player weapon_player;

weapon::weapon()
{
	weapon_reticle = { 0, 0 };
	is_reloading = false;
	current_weapon = fists;
	clips = 2;
}
weapon::weapon(int bull_speed, int bull_amount) 
{
	this->bullet_speed = bull_speed;
	this->bullet_amount = bull_amount;

	if (bullet_amount == 0)
	{
		clips -= 1;
		std::cout << clips;

		if (clips == 0)
		{
			bullet_amount = 0;
		}
	}
}
weapon::~weapon()
{

}
void weapon::fire(weapon &curr_weapon)
{
	//Could possibly use later if speed is on Vector2. For now just use given value.
	/*Vector2 direction = {cos(PI / 180), -sin(PI / 180)};
	Vector2 bullet_velocity = Vector2Scale(direction, bullet_speed);*/
	if (bullet_amount > 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		bullets.push_back(bullet(Vector2MoveTowards(weapon_player.player_object, weapon_reticle, 1), bullet_speed));
		curr_weapon.bullet_amount -= 1;
		std::cout << bullet_amount;
	}

}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}
void weapon::take_input()
{
	if (current_weapon == revolver)
	{
	}
	
}

void weapon::reload()
{
	if (IsKeyPressed(KEY_R) && current_weapon == revolver && clips > 1)
	{
		bullet_amount = 6;
	}
	else if (IsKeyPressed(KEY_R) && current_weapon == repeater && clips > 1)
	{
		bullet_amount = 12;
	}
}
