#include "revolver.h"


revolver::revolver(int bullets, int bullet_damage, int bullet_velocity)
{
	active = true;
	revolver_reticle = { 0, 0 };

	this->bullets = bullets;
	this->bullet_damage = bullet_damage;
	this->bullet_velocity = bullet_velocity;


}
revolver::~revolver()
{
	

}
void revolver::draw(Vector2 player_object)
{
	revolver_reticle = GetMousePosition();
	DrawCircleV(revolver_reticle + player_object, 8, RED);
}
Vector2 revolver::get_revolver_reticle()
{
	return revolver_reticle;
}

