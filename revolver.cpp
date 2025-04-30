#include "revolver.h"

revolver::revolver(int bm, int bs) : weapon(bm, bs)
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
	if (bullet_amount < 1)
	{
		return;
	}
}
