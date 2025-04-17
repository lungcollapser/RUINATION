#include "camera.h"


camera::camera()
{
	player_camera = { 0 };
	player_camera.target = { 0, 0 };
	player_camera.offset = Vector2{ 800 / 2.0f, 800 / 2.0f };
	player_camera.rotation = 0.0f;
	player_camera.zoom = 0.7f;
	camera_speed = 900;
	
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
	Vector2 direction = { 0,0 };

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
	
	Vector2 velocity = Vector2Scale(Vector2Normalize(direction), camera_speed * GetFrameTime());
	player_camera.target = Vector2Add(player_camera.target, velocity);

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		camera_speed = 4;
	}
	else
	{
		camera_speed = 8;
	}
}
