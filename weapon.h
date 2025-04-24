#pragma once
#include "bullet.h"
#include "player.h"
#include "include.h"


class weapon
{
private:
	bool is_reloading;
protected:
	float bullet_speed;
	float bullet_spread;
public:
	weapon();
	~weapon();
	void draw(Vector2 player_object);
	void fire();
	void take_input();
	Vector2 weapon_reticle;
	Vector2 weapon_range_limit;
	std::vector<bullet> bullets;

};