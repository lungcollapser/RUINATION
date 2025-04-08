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
public:
	weapon();
	~weapon();
	void draw(Vector2 player_object);
	void fire();
	void draw(Vector2 player_object);
	Vector2 weapon_reticle;
	std::vector<bullet> bullets;
	

};