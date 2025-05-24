#pragma once
#include "include.h"
#include "revolver.h"
#include "repeater.h"

class player
{
protected:
	int player_speed;
	Vector2 player_reticle;
public:
	//constructor
	player();
	//destructor
	~player();
	//player actions
	void draw();
	//player movement
	void take_input();
	//player attributes
	Vector2 player_object;
	std::vector<bullet>& get_bullets();
	weapon *current_weapon;
	revolver *revolver_player;
	repeater *repeater_player;
};