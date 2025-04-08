#include "revolver.h"


revolver::revolver() : weapon()
{
	active = true;
	mag_bullets = 6;
}
revolver::~revolver()
{
	

}

Vector2 revolver::get_revolver_reticle()
{
	return weapon_reticle;
}

