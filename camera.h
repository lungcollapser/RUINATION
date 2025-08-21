#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "include.h"
#include "player.h"

struct camera
{
	uint16 camera_speed;
};
Camera2D camera_main;
Camera2D* camera_main_ptr;

void init_cam(Camera2D* camera_ptr);
void free_cam(camera* camera_ptr);
void update_cam(camera* camera_ptr);
#endif