#include "revolver.h"


revolver::revolver() : weapon()
{
	active = true;
	weapon_reticle = { 0, 0 };
	mag_bullets = 6;
	bullet_speed = 1000;
	bullet_damage = 1;
}
revolver::~revolver()
{
	

}
void revolver::draw(Vector2 player_object)
{
	weapon_reticle = GetMousePosition();
	DrawCircleV(weapon_reticle + player_object, 8, RED);
}
Vector2 revolver::get_revolver_reticle()
{
	return weapon_reticle;
}

