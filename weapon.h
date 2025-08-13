#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "include.h"
#include "bullet.h"

class revolver;
class repeater;

enum current_weapon
{
	revolver = 1,
	repeater = 2
};

struct revolver
{
	
	
	uint16 bullet_speed;
	uint16 bullet_amount;
	uint16 bullet_damage;
	uint16 max_bullets;
	uint16 clips;
	uint16 current_clips;
	v2 weapon_reticle;

	std::vector<bullet> bullets;
	
};
void init_w();
void free_w();
void draw_w(v2 player_object);
void fire_w(std::vector<bullet> bullets, v2 weapon_reticle, v2 center_position, uint16 bullet_speed, uint16 bullet_amount);
void take_input_w();
std::vector<bullet> get_bullets();


#endif