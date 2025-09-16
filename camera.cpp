#include "camera.h"

extern camera camera_main = { 0 };

void init_cam()
{
	camera_main.camera = { 0 };
	camera_main. camera.target = { 0, 0 };
	camera_main.camera.zoom = 1.0;
	camera_main.camera_speed = 525;
}

void update_cam()
{
	camera_main.camera.offset = { screen_size_x / 2.0f, screen_size_y / 2.0f };

	v2 direction = { 0, 0 };

	if (IsKeyDown(KEY_D))
	{
		direction.x++;
	}
	if (IsKeyDown(KEY_A))
	{
		direction.x--;
	}
	if (IsKeyDown(KEY_W))
	{
		direction.y--;
	}
	if (IsKeyDown(KEY_S))
	{
		direction.y++;
	}
	
	Vector2 velocity =   Vector2Scale(Vector2Normalize(direction), camera_main.camera_speed * GetFrameTime());
	camera_main.camera.target = Vector2Add(camera_main.camera.target, velocity);


	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		camera_main.camera_speed = 325;
	}
	else
	{
		camera_main.camera_speed = 525;
	}

}
