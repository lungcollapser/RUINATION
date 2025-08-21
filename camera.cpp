#include "camera.h"

player camera_player;


void init_cam(Camera2D* camera_ptr)
{
	camera_main_ptr = (Camera2D*)malloc(sizeof(Camera2D));

	camera_main = { 0 };
	camera_main.target = { 0, 0 };
	camera_speed = 525;
}
void free_cam(camera* camera_ptr)
{

}
void update_cam(camera* camera_ptr)
{

	camera_main.offset = { screen_size_x / 2.0f, screen_size_y / 2.0f };

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
	camera_main.target = Vector2Add(camera_main.target, velocity);


	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		camera_speed = 325;
	}
	else
	{
		camera_speed = 525;
	}
}
