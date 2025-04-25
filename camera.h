#pragma once
#include "include.h"
#include "player.h"

class camera
{
public:

	camera();
	~camera();
	void update();
	void take_input();

	Camera2D player_camera;
	int camera_speed;
	
};