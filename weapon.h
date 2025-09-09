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


extern weapon weapon_main;

void init_weapon();
void draw_weapon(v2 player_object);
void fire_weapon(v2 center_position);
void update_weapon(v2 center_position, v2 player_object);

#endif