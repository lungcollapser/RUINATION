#pragma once
#include "include.h"
#include "player.h"

class camera
{
private:
	int camera_speed;
public:
	camera();
	~camera();
	void update();
	void take_input();
	Camera2D player_camera;
};