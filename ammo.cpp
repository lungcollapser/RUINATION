#include "ammo.h"

ammo::ammo()
{
	ammo_drop = { 450, 450 };
	clips_drop = { 450, 450 };
}
void ammo::draw_clips()
{
	DrawCircleV(clips_drop, 20, YELLOW);
	DrawCircleV(ammo_drop, 20, ORANGE);
	switch (ammo_state)
	{
		dropped: DrawRectangleLinesEx(get_clips_rectangle(), 3, PURPLE);
	}

}
Rectangle ammo::get_clips_rectangle()
{
	return Rectangle{ clips_drop.x - 25, clips_drop.y - 25, 50, 50 };
}