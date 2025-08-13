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
void fire_w(std::vector<bullet> bullets, v2 &weapon_reticle, v2 &center_position, uint16 bullet_speed, uint16 bullet_amount)
{
	
	bullets.push_back(bullet(Vector2Normalize(Vector2Subtract(weapon_reticle, center_position)), bullet_speed));
	bullet_amount -= 1;
	
}
void take_input_w(weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon)
{
	if (IsKeyPressed(KEY_ONE))
	{
		current_weapon = revolver_weapon;
	}
	else if (IsKeyPressed(KEY_TWO))
	{
		current_weapon = repeater_weapon;
	}


	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && current_weapon->bullet_amount > 0)
	{
		current_weapon->fire(current_weapon->weapon_reticle, center_position, current_weapon->bullet_speed);
	}

	if (IsKeyPressed(KEY_R) && current_weapon->current_clips >= 1 && current_weapon->bullet_amount < current_weapon->max_bullets)
	{
		current_weapon->bullet_amount = current_weapon->max_bullets;
		current_weapon->current_clips -= 1;
	}
}
std::vector<bullet> get_bullets(std::vector<bullet> bullets)
{
	return bullets;
}


