#include "revolver.h"


revolver::revolver() : weapon()
{
	active = true;
	this -> weapon_reticle = weapon_reticle = { 0, 0 };
	mag_bullets = 6;
	bullet_speed = 1000;
	bullet_damage = 1;
}
revolver::~revolver()
{
	

}

Vector2 revolver::get_revolver_reticle()
{
	return weapon_reticle;
}

