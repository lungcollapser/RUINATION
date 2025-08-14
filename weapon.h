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
void init_w();
void free_w();
void draw_w(v2 player_object, v2 weapon_reticle);
void fire_w(v2 center_position, weapon* weapon, std::vector<bullet> bullets);
void update_w(weapon* current_weapon, v2 weapon_reticle, v2 center_position, uint16 bullet_speed, uint16 bullet_amount);
std::vector<bullet>& get_bullets(std::vector<bullet> bullets);

#endif