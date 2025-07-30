#include "player.h"

//constructor
player::player()
{
	//initializations
	player_object = { 0, 0 };
	player_speed = 525;

	current_weapon = new weapon();
	revolver_weapon = new revolver();
	repeater_weapon = new repeater();

	revolver_weapon->bullet_amount = revolver_weapon->max_bullets;
	repeater_weapon->bullet_amount = repeater_weapon->max_bullets;
}
//destructor
player::~player()
{

	//for some reason, deleting the current_weapon results in an exception being thrown. LOOK INTO THIS
	delete revolver_weapon;
	delete repeater_weapon;

}
//player drawings
void player::draw()
{
	DrawCircleV(player_object, 25, WHITE);
	current_weapon->draw(player_object);

}

//player movements
void player::take_input(Vector2 &center_position)
{
	Vector2 direction = { 0.0f, 0.0f };

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

	Vector2 velocity = Vector2Scale(Vector2Normalize(direction), player_speed * GetFrameTime());
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
		std::cout << current_weapon->current_clips;
	}
	else if (IsKeyPressed(KEY_TWO))
	{
		current_weapon = repeater_weapon;
		std::cout << current_weapon->current_clips;
	}
	
	
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && current_weapon->bullet_amount > 0)
	{
		current_weapon->fire(current_weapon->weapon_reticle, center_position, current_weapon->bullet_speed);
		std::cout << current_weapon->bullet_amount;
	}

	if (IsKeyPressed(KEY_R) && current_weapon->current_clips >= 1 && current_weapon->bullet_amount < current_weapon->max_bullets)
	{
		current_weapon->bullet_amount = current_weapon->max_bullets;
		current_weapon->current_clips -= 1;
	}
	
}
Rectangle player::get_rectangle()
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}
std::vector<bullet> player::get_bullets()
{
	return current_weapon->bullets;
}





