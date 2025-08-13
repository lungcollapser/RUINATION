#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "include.h"
#include "bullet.h"



struct weapon
{
	
	
	uint16 bullet_speed;
	uint16 bullet_amount;
	uint16 bullet_damage;
	uint16 max_bullets;
	uint16 clips;
	uint16 current_clips;
	v2 weapon_reticle;

	std::vector<bullet> bullets;
	std::vector<bullet>& get_bullets();

	void fire_w(v2 center_position);
	
};
void init_w();
void free_w();
void draw_w(v2 player_object, v2 weapon_reticle);
void update_w(weapon* current_weapon, v2 weapon_reticle, v2 center_position, uint16 bullet_speed, uint16 bullet_amount);



#endif