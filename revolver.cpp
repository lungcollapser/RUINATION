#include "revolver.h"

revolver::revolver() 
{
	active = true;
	this->bullet_spread = 0;
	this->bullet_speed = 4000;
	this->bullet_amount = 6;
	
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
