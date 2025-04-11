#pragma once
#include "include.h"

class camera
{
public:

	camera();
	~camera();
	void update();
	void camera_input();
	void get_position();
	void set_position();
	void get_speed();
	void set_speed();

	Camera2D player_camera;
	float camera_speed;

};