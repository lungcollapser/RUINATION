#pragma once
#include "revolver.h"
#include "repeater.h"
#include "include.h"


class player
{
protected:
	int player_speed;
	Vector2 player_reticle;
public:
	player();
	~player();
	void draw();
	void take_input(Vector2 &center_position);
	Rectangle get_rectangle();
	Vector2 player_object;
	std::vector<bullet>& get_bullets();
	weapon *current_weapon;
	revolver *revolver_player;
	repeater *repeater_player;
};