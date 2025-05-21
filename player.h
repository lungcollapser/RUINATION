#pragma once
#include "include.h"
#include "weapon.h"
#include "revolver.h"

class player
{
protected:
	int player_speed;
	revolver *revolver_player;
	weapon *current_weapon;
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
};