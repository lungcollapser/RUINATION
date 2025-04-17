#pragma once
#include "weapon.h"
#include "include.h"


class player
{
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
	float player_speed;







};