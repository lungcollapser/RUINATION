#include "player.h"

weapon player_weapon;

//constructor
player::player()
{
	//initializations
	player_object = { 400, 400 };
	player_speed = 8;
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
	
	player_weapon.fire();
}

