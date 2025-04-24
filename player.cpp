#include "player.h"

weapon player_weapon;

//constructor
player::player()
{
	//initializations
	player_object = { 0, 0 };
	player_speed = 100;

}
//destructor
player::~player()
{

}
//player drawings
void player::draw()
{
	DrawCircleV(player_object, 25, WHITE);
	
}
//player movements
void player::take_input()
{

	Vector2 direction = { 0,0 };

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

	if (IsKeyDown(KEY_R))
	{
		return;
	}

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		player_weapon.fire();
	}
}




