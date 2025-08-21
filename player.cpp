#include "player.h"

void init_p()
{

	if (player_main == NULL)
	{
		std::cout << "memory allocation player failed";
	}


	player_main->player_object = { 0, 0 };
	player_main->player_speed = 525;
}
void free_p()
{
	free(player_main);
}
void draw_p()
{

	DrawCircleV(player_main->player_object, 25, WHITE);
}

void update_p()
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

	v2 velocity = Vector2Scale(Vector2Normalize(direction), player_main->player_speed * GetFrameTime());
	player_main->player_object = Vector2Add(player_main->player_object, velocity);

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		player_main->player_speed = 325;
	}
	else
	{
		player_main->player_speed = 525;
	}
	
}
Rectangle get_rectangle(v2 player_object)
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}






