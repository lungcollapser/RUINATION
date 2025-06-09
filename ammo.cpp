#include "ammo.h"

ammo::ammo()
{
	ammo_drop = { 450, 450 };
	clips_drop = { 450, 450 };
	current_state = dropped;
}
void ammo::draw_clips()
{
	switch (current_state)
	{
	case 0: DrawCircleV(clips_drop, 20, YELLOW); break;
	case 1: break;
	}
}
Rectangle ammo::get_clips_rectangle()
{
	return Rectangle{ clips_drop.x - 25, clips_drop.y - 25, 50, 50 };
}