#include "enemy.h"


enemy::enemy()
{
	enemy_object = { 200, 300 };
	enemy_health = 1;
	enemy_speed = 100;
	current_state = alive;

	enemy_weapon = new weapon();
	
	enemy_weapon->bullet_speed = 300;


}
enemy::~enemy()
{

}
std::vector<bullet>& enemy::get_bullets()
{
	return enemy_weapon->get_bullets(enemy_weapon);
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
	enemy_weapon->fire(player_object, enemy_object, bullet_speed);
}
void enemy::update_position()
{

}
Rectangle enemy::get_rectangle()
{
	return Rectangle{ enemy_object.x - 25, enemy_object.y - 25, 50, 50 };
}