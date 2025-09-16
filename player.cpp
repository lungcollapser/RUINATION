#include "player.h"


void init_player(player *player)
{
	player->player_object = { 0, 0 };
	player->player_speed = 525;
}
void draw_player(player *player)
{

	DrawCircleV(player->player_object, 25, WHITE);
}

void update_player(player *player)
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

	v2 velocity = Vector2Scale(Vector2Normalize(direction), player->player_speed * GetFrameTime());
	player->player_object = Vector2Add(player->player_object, velocity);

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		player->player_speed = 325;
	}
	else
	{
		player->player_speed = 525;
	}
	
}

Rectangle get_rectangle_player(v2 player_object)
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}
