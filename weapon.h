#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "include.h"
#include "bullet.h"


enum weapon_type
{
	fists, revolver, repeater
};
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


local_persist weapon* weapon_main;
void init_w(weapon *weapon_init);
void free_w(weapon *weapon);
void draw_w(v2 player_object, weapon* weapon);
void fire_w(v2 center_position, weapon* weapon);
void update_w(weapon* weapon, v2 center_position);
std::vector<bullet>& get_bullets(weapon* weapon);

#endif