#include "player.h"

weapon player_weapon;

//constructor
player::player()
{
	//initializations
	player_object = { 400, 400 };
	player_speed = 3;
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
	if (IsKeyDown(KEY_D))
	{
		player_object.x++
	}
	else if (IsKeyDown(KEY_A))
	{
		player_object.x--;
	}
	else if (IsKeyDown(KEY_W))
	{
		player_object.y--;
	}
	else if (IsKeyDown(KEY_S))
	{
		player_object.y++;
	}
}
void player::walk()
{
	player_speed = 4;
}
void player::reload()
{
	return;
}
void player::shoot()
{
	
	player_weapon.fire();
}

