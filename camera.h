#pragma once
#include "include.h"

class camera
{
public:

	camera();
	~camera();
	void update();
	void camera_input();

	Camera2D player_camera;
	float camera_speed;

};