#include "enemy.h"

//TDOD: Delete enemy instaead of just slowing its speed.

enemy::enemy()
{
	enemy_health = 10;
	enemy_speed = 3;
	enemy_radius = 30;
	current_state = alive;
}
enemy::~enemy()
{

}
void enemy::draw()
{
	if (current_state == alive)
	{
		DrawCircleV(enemy_object, enemy_radius, PURPLE);
	}
	else
	{
		return;
	}

}

void enemy::update(Vector2& player_object)
{

	if (current_state == aggro)
	{
		enemy_object = Vector2MoveTowards(enemy_object, player_object, enemy_speed);
	}
	else if (current_state == neutral)
	{
		return;
	}

	if (enemy_health <= 0)
	{
		current_state = dead;
	}

}
int enemy::take_damage(int damage)
{
	enemy_health -= damage;
	
	return damage;
}
