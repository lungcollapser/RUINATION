#pragma once
#include "player.h"
#include "bullet.h"
#include "weapon.h"
#include "include.h"
#include "camera.h"

class game
{
public:
	//constructor
	game();
	//destructor
	~game();
	//game drawing
	void draw();
	//game updating
	void update();
	//game input
	void handle_input();
	//game running boolean
	bool run;
};