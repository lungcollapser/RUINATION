#include "player.h"

void init_p(player* player_init)
{
	player_main = (player*)malloc(sizeof(player));

	player_init->player_object = { 0, 0 };
	player_init->player_speed = 525;
	std::cout << player_init->player_speed;
}
void free_p(player* player)
{
	free(player);
}
void draw_p(player* player)
{

	DrawCircleV(player->player_object, 25, WHITE);
}

void update_p(player* player)
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
Rectangle get_rectangle(v2 player_object)
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}






