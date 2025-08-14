#include "player.h"



//player drawings
void draw_p(v2 player_object)
{

	DrawCircleV(player_object, 25, WHITE);
}

//player movements
void update_p(v2 player_object, v2 &center_position, uint16 player_speed)
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
	
}
Rectangle get_rectangle(v2 player_object)
{
	return Rectangle{ player_object.x - 25, player_object.y - 25, 50, 50 };
}






