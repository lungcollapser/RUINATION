#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "include.h"


enum weapon_type
{
	fists, revolver, repeater
};
struct weapon
{
	
	
	uint16 bullet_amount;
	uint16 bullet_damage;
	uint16 max_bullets;
	uint16 clips;
	uint16 current_clips;
	v2 weapon_reticle;
};


void init_weapon(weapon *weapon);
void draw_weapon(weapon *weapon, v2 player_object);
void update_weapon(weapon *weapon);

#endif