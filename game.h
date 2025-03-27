#pragma once
#include "raylib.h"

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
	void update_camera();
	//game input
	void handle_input();
	//game running boolean
	bool run;
};