#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "include.h"
#include "player.h"
#include "bullet.h"

class weapon
{
public:
	weapon();
	~weapon();
	void fire(Vector2 &weapon_reticle, Vector2 &center_position, int bullet_speed);
	void draw(Vector2 &player_object);
	bullet* get_bullets();
	Vector2 weapon_reticle, center_position;
	int bullet_speed, bullet_amount, bullet_damage, max_bullets, clips, current_clips;

	bullet* bullets;
};
#endif