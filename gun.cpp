#include "gun.h"
#include <iostream>

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


