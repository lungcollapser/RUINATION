#include "ammo.h"

ammo::ammo()
{
	ammo_drop = { 450, 450 };
	clips_drop = { 450, 450 };
	ammo_state = 0;
}
void ammo::draw_clips()
{
	if (ammo_state == 0)
	{
		DrawCircleV(clips_drop, 20, YELLOW);

	}
	else
	{
		return;
	}

}
Rectangle ammo::get_clips_rectangle()
{
	return Rectangle{ clips_drop.x - 25, clips_drop.y - 25, 50, 50 };
}