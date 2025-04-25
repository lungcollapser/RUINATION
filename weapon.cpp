#include "weapon.h"

player weapon_player;


weapon::weapon()
{
	is_reloading = false;
	bullet_speed = 5;
	weapon_reticle = { 0, 0 };
	weapon_range_limit = { 450, 450 };
	bullet_spread = 0;
	bullet_speed = 3000;

}
weapon::~weapon()
{

}
void weapon::fire()
{
	//Could possibly use later if speed is on Vector2. For now just use given value.
	/*Vector2 direction = {cos(PI / 180), -sin(PI / 180)};
	Vector2 bullet_velocity = Vector2Scale(direction, bullet_speed);*/
	bullets.push_back(bullet(Vector2MoveTowards(weapon_player.player_object, weapon_reticle, 1), bullet_speed));
	std::cout << "shoot";
	
}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);

	weapon_range_limit = player_object;
	DrawCircleV(weapon_range_limit, 8, PINK);
}
void weapon::take_input()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		fire();
	}
}