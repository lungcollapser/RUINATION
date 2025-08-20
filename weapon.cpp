#include "weapon.h"



void init_w(weapon* weapon_init)
{

	weapon_main = (weapon*)malloc(sizeof(weapon));

	weapon_init->bullet_amount = 6;
	weapon_init->bullet_speed = 4000;
	weapon_init->current_clips = 1;
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


