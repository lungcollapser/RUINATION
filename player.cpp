#include "player.h"
#include "gun.h"
#include "raylib.h"
#include <iostream>

//constructor
player::player()
{
	//initializations
	player_object = { 400, 400 };
	player_reticle = { 0, 0 };
	player_speed = 8;
}
//destructor
player::~player()
{

}
//player drawings
void player::draw()
{
	player_reticle = GetMousePosition();
	DrawCircleV(player_object, 25, WHITE);
	DrawCircleV(player_object + player_reticle, 10, RED);
}
//player movements
void player::move_right()
{
	player_object.x += player_speed;

}
void player::move_left()
{

	player_object.x -= player_speed;
}
void player::move_up()
{
	
	player_object.y -= player_speed;
	
}
void player::move_down()
{
	player_object.y += player_speed;
	
}
void player::walk()
{
	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		player_speed = 2;
	}
	else
	{
		player_speed = 5;
	}
}
//player actions
void player::shoot()
{
	guns.push_back(gun({player_object - player_reticle}, {Vector2MoveTowards(player_object, player_reticle, 5000.0)}));
}

