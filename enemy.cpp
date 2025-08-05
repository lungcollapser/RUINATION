#include "enemy.h"

//TDOD: Delete enemy instaead of just slowing its speed.

enemy::enemy()
{
	enemy_health = 10;
	enemy_speed = 3;
	enemy_radius = 30;
	current_move_state = neutral;
	current_health_state = alive;

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
		current_health_state == dead;
	}

}
bool enemy::collision(Rectangle collision_one, Rectangle collision_two)
{
	if (CheckCollisionRecs(collision_one, collision_two))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void enemy::update(v2& player_object, float bullet_damage, Rectangle rec1, Rectangle rec2)
{
	bool enemy_collision = collision(rec1, rec2);
	
	if (current_health_state == dead)
	{
		return;
	}

	if (current_move_state == aggro)
	{
		enemy_object = Vector2MoveTowards(enemy_object, player_object, enemy_speed);
	}
	else
	{
		current_move_state == neutral;
	}

	if (enemy_collision)
	{
		take_damage(bullet_damage);
		current_move_state = aggro;
		std::cout << enemy_health;
	}

	if (enemy_health <= 0)
	{
		current_health_state = dead;
	}
	else
	{
		current_health_state = alive;
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