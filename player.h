#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "include.h"
#include "weapon.h"
#include "revolver.h"
#include "repeater.h"

class player
{
protected:
	int player_speed;
public:
	player();
	~player();
	void draw();
	void take_input(Vector2 &center_position);
	Rectangle get_rectangle();
	Vector2 player_object;
	weapon *current_weapon;
	revolver *revolver_weapon;
	repeater *repeater_weapon;

	std::vector<bullet> get_bullets();
};
#endif