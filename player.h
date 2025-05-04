#pragma once
#include "include.h"
#include "weapon.h"


class player
{
private:
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







};