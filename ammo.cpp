#include "ammo.h"

ammo::ammo()
{
	current_clips_state = dropped;
	current_ammo_state = dropped;
}
void ammo::draw_clips(Vector2 position)
{
	switch (current_clips_state)
	{
	case 0: DrawCircleV(position, 20, YELLOW); DrawRectangleLinesEx(get_clips_rectangle(position), 3, WHITE); break;
	case 1: break;
	}
}
void ammo::draw_ammo(Vector2 position)
{
	switch (current_ammo_state)
	{
	case 0: DrawCircleV(position, 20, GREEN); DrawRectangleLinesEx(get_ammo_rectangle(position), 3, WHITE); break;
	case 1:break;
	}
}
Rectangle ammo::get_clips_rectangle(Vector2 position)
{
	return Rectangle{ position.x - 25, position.y - 25, 50, 50 };
}
Rectangle ammo::get_ammo_rectangle(Vector2 position)
{
	return Rectangle{ position.x - 25, position.y - 25, 50, 50 };
}
