#include "enemy.h"


enemy::enemy()
{
	enemy_object = { 200, 300 };
	enemy_health = 1;
	enemy_speed = 100;
	bullet_speed = 100;
	current_state = alive;
}
enemy::~enemy()
{

}
void enemy::draw()
{

	switch (current_state)
	{
	case alive: DrawCircleV(enemy_object, 30, PURPLE); DrawRectangleLinesEx(get_rectangle(), 3, WHITE); break;
	case dead: break;
	}
}
void enemy::fire(Vector2 &player_object)
{
	enemy_bullets.push_back(bullet(Vector2Normalize(Vector2Subtract(enemy_object, player_object)), bullet_speed));
}
void enemy::update_position()
{

}
Rectangle enemy::get_rectangle()
{
	return Rectangle{ enemy_object.x - 25, enemy_object.y - 25, 50, 50 };
}