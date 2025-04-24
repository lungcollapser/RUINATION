#include "camera.h"

player camera_player;

camera::camera()
{
	player_camera = { 0 };
	player_camera.target = { 0, 0 };
	player_camera.zoom = 1.0;
	camera_speed = 525;
}
camera::~camera()
{

}

void camera::update()
{
	return;
}
void camera::take_input()
{

	Vector2 direction = { 0, 0 };

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
	
	direction = Vector2Normalize(direction);
	Vector2 change_vector = Vector2Scale(direction, camera_speed * GetFrameTime());
	player_camera.target = Vector2Add(player_camera.target, change_vector);

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		camera_speed = 325;
	}
	else
	{
		camera_speed = 525;
	}
}
