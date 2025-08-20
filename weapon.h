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
	v2 weapon_reticle = { 0, 0 };

	std::vector<bullet> bullets;

};
void init_w(weapon *weapon_main);
void free_w(weapon *weapon_main);
void draw_w(v2 player_object, weapon* weapon);
void fire_w(v2 center_position, weapon* weapon);
void update_w(weapon* weapon, v2 center_position);
std::vector<bullet>& get_bullets(weapon* weapon);

#endif