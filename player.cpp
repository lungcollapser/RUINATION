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
	bullets = 6;
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
	player_speed = 4;
}
void player::reload()
{
	bullets = 6;
}

//player actions
void player::shoot()
{
	if (bullets > 0)
	{
		guns.push_back(gun({ player_object - player_reticle }, { Vector2MoveTowards(player_object, player_reticle, 5000.0) }));
		bullets--;
		std::cout << bullets;
	}
	else
	{
		return;
	}

}

