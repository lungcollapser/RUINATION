#include "camera.h"

player camera_player;

camera::camera()
{
	player_camera = { 0 };
	player_camera.target = { camera_player.player_object };
	player_camera.zoom = 1.0;
	player_camera.offset = { 1920 / 2.0f, 1080 / 2.0f };
	camera_speed = 5;
	
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
	Vector2Normalize(player_camera.target);
	Vector2 velocity = Vector2Scale(camera_speed * GetFrameTime())


	if (IsKeyDown(KEY_D))
	{
		player_camera.target.x += camera_speed;
	}
	if (IsKeyDown(KEY_A))
	{
		player_camera.target.x -= camera_speed;
	}
	if (IsKeyDown(KEY_W))
	{
		player_camera.target.y -= camera_speed;
	}
	if (IsKeyDown(KEY_S))
	{
		player_camera.target.y += velocity;
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
