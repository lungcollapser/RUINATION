#include "player.h"


void init_p(weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon)
{
	current_weapon = (weapon*)malloc(sizeof(weapon));
	revolver_weapon = (revolver*)malloc(sizeof(revolver));
	repeater_weapon = (repeater*)malloc(sizeof(repeater));

}
void free_p(weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon)
{
	free(current_weapon);
	free(revolver_weapon);
	free(repeater_weapon);
}
//player drawings
void draw_p(v2 player_object)
{
	DrawCircleV(player_object, 25, WHITE);
}

//player movements
void take_input_p(v2 player_object, weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon, v2 &center_position, uint16 player_speed)
{
	v2 direction = { 0.0f, 0.0f };

	if (IsKeyDown(KEY_D))
	{
		direction.x++;
	}
	if (IsKeyDown(KEY_A))
	{
		direction.x--;
	}
	if (IsKeyDown(KEY_W))
	{
		direction.y--;
	}
	if (IsKeyDown(KEY_S))
	{
		direction.y++;
	}

	v2 velocity = Vector2Scale(Vector2Normalize(direction), player_speed * GetFrameTime());
	player_object = Vector2Add(player_object, velocity);

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		player_speed = 325;
	}
	else
	{
		player_speed = 525;
	}


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
Rectangle get_rectangle(v2 player_object)
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}
std::vector<bullet>& get_bullets(weapon* current_weapon)
{
	return current_weapon->bullets;
}





