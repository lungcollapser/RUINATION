#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "include.h"

struct camera
{
	Camera2D camera;
	uint16 camera_speed;
};

local_persist camera* camera_main;

void init_cam();
void free_cam();
void update_cam();
#endif