#pragma once
#include "bullet.h"
#include "player.h"
#include "include.h"


class weapon
{
private:
	bool is_reloading;
protected:
	int mag_bullets;
	int bullet_damage;
	float bullet_speed;
	float bullet_spread;
	float angle;
public:
	weapon();
	~weapon();
	void draw(Vector2 player_object);
	void fire();
	Vector2 weapon_reticle;
	Vector2 weapon_range_limit;

};