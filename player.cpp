#include "player.h"

extern player player_main = { 0 };

void init_player ()
{
	player_main.player_object = { 0, 0 };
	player_main.player_speed = 525;
}

void draw_player()
{

	DrawCircleV(player_main.player_object, 25, WHITE);
}

void update_player()
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

	v2 velocity = Vector2Scale(Vector2Normalize(direction), player_main.player_speed * GetFrameTime());
	player_main.player_object = Vector2Add(player_main.player_object, velocity);

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		player_main.player_speed = 325;
	}
	else
	{
		player_main.player_speed = 525;
	}
	
}
Rectangle get_rectangle_player(v2 player_object)
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}






