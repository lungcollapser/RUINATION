#include "weapon.h"



void init_w()
{
}
void free_w()
{

}
void draw_w(v2 player_object, v2 weapon_reticle)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}
void fire_w(v2 center_position, weapon* weapon, std::vector<bullet> bullets)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && weapon->bullet_amount > 0)
	{
		bullets.push_back(bullet(Vector2Normalize(Vector2Subtract(weapon->weapon_reticle, center_position)), weapon->bullet_speed));
		weapon->bullet_amount -= 1;
	}

}
void update_w(weapon* current_weapon, v2 weapon_reticle, v2 center_position, uint16 bullet_speed, uint16 bullet_amount)
{
	

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && current_weapon->bullet_amount > 0)
	{
		fire_w(center_position, current_weapon, current_weapon->bullets);
	}

	if (IsKeyPressed(KEY_R) && current_weapon->current_clips >= 1 && current_weapon->bullet_amount < current_weapon->max_bullets)
	{
		current_weapon->bullet_amount = current_weapon->max_bullets;
		current_weapon->current_clips -= 1;
	}
}

std::vector<bullet>& get_bullets(std::vector<bullet> bullets)
{
	return bullets;
}


