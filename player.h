#pragma once
#include "include.h"
#include "revolver.h"

class player
{
protected:
	int player_speed;
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
	weapon current_weapon;
	revolver revolver_player;
};