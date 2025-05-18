#include "enemy.h"


enemy::enemy()
{
	enemy_object = { 200, 300 };
	enemy_health = 1;
	enemy_speed = 100;
	enemy_state = 0;
}
enemy::~enemy()
{

}
void enemy::draw()
{
	DrawCircleV(enemy_object, 30, PURPLE);
}
void enemy::update_position()
{

}
void enemy::enemy_hitbox(Vector2 projectile)
{
	if (projectile == enemy_object)
	{
		enemy_health -= 1;
		std::cout << "ayo";
	}
}