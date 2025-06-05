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
	if (enemy_state == 0)
	{
		DrawCircleV(enemy_object, 30, PURPLE);
		DrawRectangleLinesEx(get_rectangle(), 3, WHITE);
	}
	else
	{
		return;
	}
	
}
void enemy::update_position()
{

}
Rectangle enemy::get_rectangle()
{
	return Rectangle{ enemy_object.x - 25, enemy_object.y - 25, 50, 50 };
}