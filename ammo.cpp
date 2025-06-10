#include "ammo.h"

ammo::ammo()
{
	ammo_drop = { 750, 750 };
	clips_drop = { 450, 450 };
	current_clips_state = dropped;
	current_ammo_state = dropped;
}
void ammo::draw_clips()
{
	switch (current_clips_state)
	{
	case 0: DrawCircleV(clips_drop, 20, YELLOW); DrawRectangleLinesEx(get_clips_rectangle(), 3, WHITE); break;
	case 1: break;
	}
}
void ammo::draw_ammo()
{
	switch (current_ammo_state)
	{
	case 0: DrawCircleV(ammo_drop, 20, GREEN); DrawRectangleLinesEx(get_ammo_rectangle(), 3, WHITE); break;
	case 1:break;
	}
}
Rectangle ammo::get_clips_rectangle()
{
	return Rectangle{ clips_drop.x - 25, clips_drop.y - 25, 50, 50 };
}
Rectangle ammo::get_ammo_rectangle()
{
	return Rectangle{ ammo_drop.x - 25, ammo_drop.y - 25, 50, 50 };
}
