#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "include.h"
#include "revolver.h"
#include "repeater.h"


struct player_attributes
{
	uint16 player_speed;
	v2 player_object;
	
};
void draw_p(v2 player_object);
void take_input_p(v2 player_object, weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon, v2& center_position, uint16 player_speed);
void init_p(weapon * current_weapon);
void free_p(weapon* current_weapon, revolver* revolver_weapon, repeater* repeater_weapon);
Rectangle get_rectangle(v2 player_object);
std::vector<bullet>& get_bullets(weapon* current_weapon);
#endif