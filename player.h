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
	//constructor
	player();
	//destructor
	~player();
	//player actions
	void draw();
	//player movement
	void take_input(Vector2 &center_position);
	void player_update(Rectangle object);
	//player attributes
	Vector2 player_object;
	Rectangle collision;
	std::vector<bullet>& get_bullets();
	weapon *current_weapon;
	revolver *revolver_player;
	repeater *repeater_player;
};