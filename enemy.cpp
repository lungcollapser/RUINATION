#include "enemy.h"


enemy::enemy()
{
	enemy_health = 1;
	enemy_speed = 3;
	current_state = alive;

	enemy_weapon = new weapon();
	enemy_weapon->bullet_speed = 3000;
	enemy_weapon->bullet_amount = 4;


}
enemy::~enemy()
{
	delete enemy_weapon;
}
std::vector<bullet> enemy::get_bullets()
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
void enemy::fire(Vector2 &player_object, Vector2 &center_position)
{
	if (enemy_weapon->bullet_amount > 0)
	{
		enemy_weapon->fire(player_object, center_position, bullet_speed);
	}
}
void enemy::update_position(Vector2 &player_object)
{
	enemy_object = Vector2MoveTowards(enemy_object, player_object, enemy_speed);

}
Rectangle enemy::get_rectangle()
{
	return Rectangle{ enemy_object.x - 25, enemy_object.y - 25, 50, 50 };
}