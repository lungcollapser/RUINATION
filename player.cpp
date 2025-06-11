#include "player.h"


//constructor
player::player()
{
	//initializations
	player_speed = 525;

	current_weapon = new weapon();
	revolver_player = new revolver();
	repeater_player = new repeater();

	revolver_player->bullet_amount = revolver_player->max_bullets;
	repeater_player->bullet_amount = repeater_player->max_bullets;

	revolver_player->current_clips = 2;
	repeater_player->current_clips = 2;

}
//destructor
player::~player()
{
	delete revolver_player;
	delete repeater_player;
}
//player drawings
void player::draw()
{
	DrawCircleV(player_object, 25, WHITE);
	current_weapon->draw(player_object);
	DrawRectangleLinesEx(get_rectangle(), 3, PURPLE);

}

std::vector<bullet>& player::get_bullets()
{
	return current_weapon->bullets;
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


	if (IsKeyPressed(KEY_ONE))
	{
		current_weapon = revolver_player;
		std::cout << current_weapon->current_clips;
	}
	else if (IsKeyPressed(KEY_TWO))
	{
		current_weapon = repeater_player;
		std::cout << current_weapon->current_clips;
	}
	
	if (current_weapon->bullet_amount > 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		current_weapon->fire(center_position);
	} 

	if (IsKeyPressed(KEY_R) && current_weapon->current_clips >= 1 && current_weapon->bullet_amount < current_weapon->max_bullets)
	{
		current_weapon->bullet_amount = current_weapon->max_bullets;
		current_weapon->current_clips -= 1;
		std::cout << "reloard";
	}
	
}
Rectangle player::get_rectangle()
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}





