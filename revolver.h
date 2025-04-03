#pragma once
#include "include.h"
#include "weapon.h"

class revolver : public weapon
{
private:
	bool active;
	Vector2 revolver_reticle;
	std::string weapon;
	int bullets;
	int bullet_damage;
	int bullet_velocity;

public:
	revolver(int bullets, int bullet_damage, int bullet_velocity);
	~revolver();
	void draw(Vector2 player_object);
	Vector2 get_revolver_reticle();

};