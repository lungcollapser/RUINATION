#include "ammo.h"

ammo::ammo()
{
}
void ammo::draw_clips()
{
	switch (current_clips_state)
	{
	case 0: DrawCircleV(clips_drop, 20, YELLOW); DrawRectangleLinesEx(get_clips_rectangle(), 3, WHITE); break;
	case 1: break;
	}
}
Vector2 ammo::draw_ammo(Vector2 position)
{
	switch (current_ammo_state)
	{
	case 0: DrawCircleV(position, 20, GREEN); DrawRectangleLinesEx(get_ammo_rectangle(position), 3, WHITE); break;
	case 1:break;
	}
	return position;
}
Rectangle ammo::get_clips_rectangle()
{
	return Rectangle{ clips_drop.x - 25, clips_drop.y - 25, 50, 50 };
}
Rectangle ammo::get_ammo_rectangle(Vector2 position)
{
	return Rectangle{ position.x - 25, position.y - 25, 50, 50 };
}
