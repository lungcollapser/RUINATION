#pragma once
#include "bullet.h"
#include "player.h"
#include "include.h"

class weapon
{
private:
	bool is_reloading;
protected:
	Vector2 weapon_reticle;
	int mag_bullets;
	int bullet_damage;
	int bullet_speed;
public:
	weapon();
	~weapon();
	void fire();
	std::vector<bullet> bullets;

};