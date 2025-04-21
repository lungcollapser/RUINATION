#include "revolver.h"


revolver::revolver() : weapon()
{
	active = true;
}
revolver::~revolver()
{
	

}

Vector2 revolver::get_revolver_reticle()
{
	return weapon_reticle;
}

