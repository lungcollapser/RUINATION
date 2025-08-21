#include "weapon.h"



void init_w(weapon* weapon_init)
{

	weapon_main = (weapon*)malloc(sizeof(weapon));
	
}
void free_w(weapon* weapon)
{
	free(weapon);
}
void draw_w(v2 player_object, weapon* weapon)
{
	weapon->weapon_reticle = GetMousePosition();
	DrawCircleV(weapon->weapon_reticle + player_object, 8, RED);
}
void fire_w(v2 center_position, weapon* weapon)
{

	weapon->bullets.push_back(bullet(Vector2Normalize(Vector2Subtract(weapon->weapon_reticle, center_position)), weapon->bullet_speed));
	weapon->bullet_amount -= 1;

}
void update_w(weapon* weapon, v2 center_position)
{
	weapon_type weapon_choice;

	if (IsKeyPressed(KEY_ONE))
	{
		weapon_choice = revolver;

		if (weapon_choice == revolver)
		{
			weapon->bullet_speed = 1000;
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
			weapon->bullet_speed = 2000;
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

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && weapon->bullet_amount > 0)
	{
		fire_w(center_position, weapon);
	}

	if (IsKeyPressed(KEY_R) && weapon->current_clips >= 1 && weapon->bullet_amount < weapon->max_bullets)
	{
		weapon->bullet_amount = weapon->max_bullets;
		weapon->current_clips -= 1;
	}
}

std::vector<bullet>& get_bullets(weapon* weapon)
{
	return weapon->bullets;
}


