#include "camera.h"


camera::camera()
{
	player_camera = { 0 };
	player_camera.target = { 400, 400 };
	player_camera.offset = Vector2{ 800 / 2.0f, 800 / 2.0f };
	player_camera.rotation = 0.0f;
	player_camera.zoom = 0.7f;
	camera_speed = 8;
	
}
camera::~camera()
{

}

void camera::update()
{
	player_camera.zoom += GetMouseWheelMove() * 0.05;
	
}
void camera::camera_input()
{
	if (IsKeyDown(KEY_D))
	{
		player_camera.target.x++
	}
	else if (IsKeyDown(KEY_A))
	{
		player_camera.target.x--;
	}
	else if (IsKeyDown(KEY_W))
	{
		player_camera.target.y--
	}
	else if (IsKeyDown(KEY_S))
	{
		player_camera.target.y++
	}

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		camera_speed = 4;
	}
	else
	{
		camera_speed = 8;
	}
}
