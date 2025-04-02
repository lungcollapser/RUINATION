#include "player.h"

gun gun_player;

//constructor
player::player()
{
	//initializations
	player_object = { 400, 400 };
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
	DrawCircleV(player_object, 25, WHITE);
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
	return;
}
void player::shoot()
{
	bullets.push_back(bullet({ player_object + gun_player.get_gun_reticle()}, {1, 1}));
	std::cout << "shot";
}

