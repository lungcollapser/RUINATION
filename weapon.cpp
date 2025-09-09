#include "weapon.h"

extern weapon weapon_main = { 0 };

void init_weapon()
{

	weapon_main.weapon_reticle = { 0, 0 };
	
}

void draw_weapon(v2 player_object)
{

	weapon_main.weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_main.weapon_reticle + player_object, 8, RED);
}
void fire_weapon(v2 center_position)
{

	weapon_main.bullet_amount -= 1;

}
void update_weapon(v2 center_position, v2 player_object)
{
	weapon_type weapon_choice;

	if (IsKeyPressed(KEY_ONE))
	{
		weapon_choice = revolver;

		if (weapon_choice == revolver)
		{
			weapon_main.clips = 2;
			weapon_main.max_bullets = 6;
			weapon_main.current_clips = 2;
			weapon_main.bullet_damage = 1;
			weapon_main.bullet_amount = 8;
		}
		std::cout << weapon_choice;
	}
	else if (IsKeyPressed(KEY_TWO))
	{
		weapon_choice = repeater;

		if (weapon_choice == repeater)
		{
			weapon_main.clips = 4;
			weapon_main.max_bullets = 12;
			weapon_main.current_clips = 2;
			weapon_main.bullet_damage = 2;
			weapon_main.bullet_amount = 12;
		}
		std::cout << weapon_choice;
	}
	else
	{
		weapon_choice = fists;
	}


	if (IsKeyPressed(KEY_R) && weapon_main.current_clips >= 1 && weapon_main.bullet_amount < weapon_main.max_bullets)
	{
		weapon_main.bullet_amount = weapon_main.max_bullets;
		weapon_main.current_clips -= 1;
	}
}



