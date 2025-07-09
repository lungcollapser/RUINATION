#include "enemy.h"

//TDOD: Delete enemy instaead of just slowing its speed.

enemy::enemy()
{
	enemy_health = 10;
	enemy_speed = 3;
	current_state = alive;
}
enemy::~enemy()
{

}
void enemy::draw()
{

	switch (current_state)
	{
	case alive: DrawCircleV(enemy_object, 30, PURPLE); break;
	case dead: enemy_speed = 0; break;
	}
}

void enemy::update(Vector2 &player_object)
{
	enemy_object = Vector2MoveTowards(enemy_object, player_object, enemy_speed);

	if (enemy_health <= 0)
	{
		current_state = dead;
	}

}
Rectangle enemy::get_rectangle()
{
	return Rectangle{ enemy_object.x - 25, enemy_object.y - 25, 50, 50 };
}