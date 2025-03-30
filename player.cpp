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
	if (bullets == 6)
	{
		DrawCircle(player_object.x + -525, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -500, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -475, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -450, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -425, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -400, player_object.y + -525, 10, BLUE);
	}
	else if (bullets == 5)
	{
		DrawCircle(player_object.x + -525, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -500, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -475, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -450, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -425, player_object.y + -525, 10, BLUE);
	}
	else if (bullets == 4)
	{
		DrawCircle(player_object.x + -525, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -500, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -475, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -450, player_object.y + -525, 10, BLUE);
	}
	else if (bullets == 3)
	{
		DrawCircle(player_object.x + -525, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -500, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -475, player_object.y + -525, 10, BLUE);
	}
	else if (bullets == 2)
	{
		DrawCircle(player_object.x + -525, player_object.y + -525, 10, BLUE);
		DrawCircle(player_object.x + -500, player_object.y + -525, 10, BLUE);
	}
	else if (bullets == 1)
	{
		DrawCircle(player_object.x + -525, player_object.y + -525, 10, BLUE);
	}
	else
	{
		return;
	}


	

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
		guns.push_back(gun({ Vector2MoveTowards(player_object, player_reticle, 100.0) }, Vector2{ 50, 50 }));
		bullets--;
		std::cout << bullets;
	}
	else
	{
		return;
	}

}

