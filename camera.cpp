#include "camera.h"

void init_cam(camera* camera_ptr)
{
	camera_main = (camera*)malloc(sizeof(camera));

	camera_ptr->camera = { 0 };
	camera_ptr->camera.target = { 0, 0 };
	camera_ptr->camera_speed = 525;
}
void free_cam(camera* camera_ptr)
{
	free(camera_ptr);
}
void update_cam(camera* camera_ptr)
{
	camera_ptr->camera.offset = { screen_size_x / 2.0f, screen_size_y / 2.0f };

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
	
	Vector2 velocity =   Vector2Scale(Vector2Normalize(direction), camera_ptr->camera_speed * GetFrameTime());
	camera_ptr->camera.target = Vector2Add(camera_ptr->camera.target, velocity);


	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		camera_ptr->camera_speed = 325;
	}
	else
	{
		camera_ptr->camera_speed = 525;
	}

}
