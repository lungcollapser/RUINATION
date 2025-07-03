#include "ammo.h"

//TODO: narrow position down so the code is less redudant. having to write that its the ammo drop position twice on ruination.cpp. once for draw and twice for collision. unnecessary 

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
void ammo::draw_ammo(Vector2 position)
{
	switch (current_ammo_state)
	{
	case 0: DrawCircleV(ammo_drop, 20, GREEN); DrawRectangleLinesEx(get_rectangle(position), 3, WHITE); break;
	case 1:break;
	}
}
Rectangle ammo::get_rectangle(Vector2 position)
{
	return Rectangle{ position.x - 25, position.y - 25, 50, 50 };
}
