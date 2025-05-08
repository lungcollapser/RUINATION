#include "weapon.h"

player weapon_player;

weapon::weapon()
{
	is_reloading = false;
	weapon_reticle = { 0, 0 };
	
}
weapon::weapon(weapon_types weapon, int bull_speed, int bull_amount)
{
	this->current_weapon = weapon;
	this->bullet_speed = bull_speed;
	this->bullet_amount = bull_amount;
}
weapon::~weapon()
{

}
void weapon::fire()
{
	//Could possibly use later if speed is on Vector2. For now just use given value.
	/*Vector2 direction = {cos(PI / 180), -sin(PI / 180)};
	Vector2 bullet_velocity = Vector2Scale(direction, bullet_speed);*/
	if (bullet_amount > 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		bullets.push_back(bullet(Vector2MoveTowards(weapon_player.player_object, weapon_reticle, 1), bullet_speed));
		bullet_amount -= 1;
	}

}
void weapon::draw(Vector2& player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);

}
void weapon::take_input()
{

	return;
}

void weapon::reload()
{
	if (IsKeyPressed(KEY_R) && current_weapon == revolver)
	{
		bullet_amount = 6;
	}
	else if (IsKeyPressed(KEY_R) && current_weapon == repeater)
	{
		bullet_amount = 12;
	}
}
void weapon::change_weapon(weapon_types new_weapon)
{
	switch (new_weapon)
	{
	case revolver: current_weapon = new_weapon; bullet_speed = 4000;
		break;
	case repeater: current_weapon = new_weapon; bullet_speed = 5000;
		break;
	}

}