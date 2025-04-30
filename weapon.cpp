#include "weapon.h"

player weapon_player;

weapon::weapon()
{
	is_reloading = false;
	weapon_reticle = { 0, 0 };
	current_weapon = "revolver";
}
weapon::weapon(int bull_am, int bull_sp)
{
	bullet_amount = bull_am;
	bullet_speed = bull_sp;
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
	
}
void weapon::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);

}
void weapon::take_input()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		fire();
		std::cout << bullet_speed;
	}

}