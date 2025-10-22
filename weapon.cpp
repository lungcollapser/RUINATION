#include "weapon.h"


void init_weapon(weapon *weapon)
{

	weapon->weapon_reticle = { 0, 0 };
	
}

void draw_weapon(weapon *weapon, v2 position)
{

	weapon->weapon_reticle = GetMousePosition();
	DrawCircleV(weapon->weapon_reticle + position, 8, RED);
}

void update_weapon(weapon *weapon)
{
	weapon_type weapon_choice;

	if (IsKeyPressed(KEY_ONE))
	{
		weapon_choice = revolver;

		if (weapon_choice == revolver)
		{
			weapon->clips = 2;
			weapon->max_bullets = 6;
			weapon->current_clips = 2;
			weapon->bullet_damage = 1;
			weapon->bullet_amount = 8;
		}
		std::cout << weapon_choice;
	}
	else if (IsKeyPressed(KEY_TWO))
	{
		weapon_choice = repeater;

		if (weapon_choice == repeater)
		{
			weapon->clips = 4;
			weapon->max_bullets = 12;
			weapon->current_clips = 2;
			weapon->bullet_damage = 2;
			weapon->bullet_amount = 12;
		}
		std::cout << weapon_choice;
	}
	else
	{
		weapon_choice = fists;
	}


	if (IsKeyPressed(KEY_R) && weapon->current_clips >= 1 && weapon->bullet_amount < weapon->max_bullets)
	{
		weapon->bullet_amount = weapon->max_bullets;
		weapon->current_clips -= 1;
	}
}
