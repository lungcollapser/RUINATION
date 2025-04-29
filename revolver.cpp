#include "revolver.h"


revolver::revolver() : weapon
{
	active = true;
}
revolver::~revolver()
{
	

}
void revolver::draw()
{

}
void revolver::reload()
{
	if (weapon.bullet_amount < 1)
	{

	}
}
