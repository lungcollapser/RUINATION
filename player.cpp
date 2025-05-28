#include "player.h"


//constructor
player::player()
{
	//initializations
	player_object = { 0.0f, 0.0f };
	player_speed = 525;

	current_weapon = new weapon();
	revolver_player = new revolver();
	repeater_player = new repeater();

	revolver_player->bullet_amount = 6;
	repeater_player->bullet_amount = 12;

	revolver_player->current_clips = 1;
	repeater_player->current_clips = 1;

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
	
}

std::vector<bullet>& player::get_bullets()
{
	return current_weapon->bullets;
}
//player movements
void player::take_input()
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
		current_weapon = revolver_player;
	}
	else if (IsKeyPressed(KEY_TWO))
	{
		current_weapon = repeater_player;
	}


	
	if (current_weapon->bullet_amount > 0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		current_weapon->fire(player_object);
		std::cout << current_weapon->bullet_amount;
	}
	else
	{
		return;
	}

	if (IsKeyPressed(KEY_R) && current_weapon->current_clips >= 1)
	{
		current_weapon->bullet_amount = 6;
	}
	
}




