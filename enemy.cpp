#include "enemy.h"

//TDOD: Delete enemy instaead of just slowing its speed.

enemy::enemy()
{
	enemy_health = 10;
	enemy_speed = 3;
	enemy_radius = 30;
	current_move_state = aggro;
	current_health_state = alive;
	bullet_collision = false;

	enemy_weapon = new weapon();
}
enemy::~enemy()
{

}
void enemy::draw()
{
	if (current_health_state == alive)
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
	bullet_collision = true;

	if (current_move_state == aggro)
	{
		enemy_object = Vector2MoveTowards(enemy_object, player_object, enemy_speed);
	}
	else if (current_move_state == neutral)
	{
		return;
	}

	if (bullet_collision)
	{
		take_damage(enemy_weapon->bullet_damage);
		current_move_state = aggro;
	}

	if (enemy_health <= 0)
	{
		current_health_state = dead;
	}

}
int enemy::take_damage(int damage)
{
	enemy_health -= damage;
	
	return damage;
}
Rectangle enemy::get_rectangle()
{
	return Rectangle{ enemy_object.x - 25, enemy_object.y - 25, 50, 50 };
}