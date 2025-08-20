#include "revolver.h"

void revolver::init_rev(revolver* revolver_init)
{
	revolver_main = (revolver*)malloc(sizeof(revolver));

	bullet_speed = 1000;
	clips = 2;
	max_bullets = 6;
	current_clips = 2;
	bullet_damage = 1;
}