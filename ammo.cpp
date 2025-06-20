#include "ammo.h"

ammo::ammo()
{
	clips_drop = { 0, 0 };
	ammo_drop = { 0, 0 };
}
void ammo::draw_clips(Vector2 position)
{
	switch (current_clips_state)
	{
	case 0: DrawCircleV(clips_drop, 20, YELLOW); DrawRectangleLinesEx(get_rectangle(position), 3, WHITE); break;
	case 1: break;
	}
}
Vector2 ammo::draw_ammo(Vector2 position)
{
	switch (current_ammo_state)
	{
	case 0: DrawCircleV(ammo_drop, 20, GREEN); DrawRectangleLinesEx(get_rectangle(position), 3, WHITE); break;
	case 1:break;
	}
	return position;
}
Rectangle ammo::get_rectangle(Vector2 position)
{
	return Rectangle{ position.x - 25, position.y - 25, 50, 50 };
}
