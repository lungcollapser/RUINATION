#include "gun.h"


gun::gun()
{
	active = true;
	gun_reticle = { 0, 0 };
}
gun::~gun()
{
	

}
void gun::draw(Vector2 player_object)
{
	gun_reticle = GetMousePosition();
	DrawCircleV(gun_reticle + player_object, 8, RED);
}
Vector2 gun::get_gun_reticle()
{
	return gun_reticle;
}

