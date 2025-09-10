#include "enemy.h"

//TDOD: Delete enemy instaead of just slowing its speed.

void init_enemy()
{
	enemy_main.enemy_health = 5;
	enemy_main.enemy_speed = 3;
	enemy_main.enemy_radius = 25;
	enemy_main.current_move_state = enemy_main.neutral;
	enemy_main.current_health_state = enemy_main.alive;
}
void draw_enemy()
{
	if (enemy_main.current_health_state == enemy_main.alive)
	{
		DrawCircleV(enemy_main.enemy_object, enemy_main.enemy_radius, PURPLE);
	}
	else
	{
		enemy_main.current_health_state = enemy_main.dead;
	}

}


void update_enemy(v2 player_object, uint16 bullet_damage)
{
	bool enemy_collision = collision_detection(rec1, rec2);
	
	if (enemy_main.current_health_state == enemy_main.dead)
	{
		return;
	}

	if (enemy_main.current_move_state == enemy_main.aggro)
	{
		enemy_main.enemy_object = Vector2MoveTowards(enemy_main.enemy_object, player_object, enemy_main.enemy_speed);
	}
	else
	{
		enemy_main.current_move_state = enemy_main.neutral;
	}

	if (enemy_collision)
	{
		take_damage(bullet_damage);
		enemy_main.current_move_state = enemy_main.aggro;
		std::cout << enemy_main.enemy_health;
	}

	if (enemy_main.enemy_health <= 0)
	{
		enemy_main.current_health_state = enemy_main.dead;
	}
	else
	{
		enemy_main.current_health_state = enemy_main.alive;
	}


}
int take_damage(int damage)
{
	enemy_main.enemy_health -= damage;
	
	return damage;
}
Rectangle get_rectangle()
{
	return Rectangle{ enemy_main.enemy_object.x - 25, enemy_main.enemy_object.y - 25, 50, 50 };
}

