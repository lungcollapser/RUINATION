#include "ammo.h"

ammo::ammo()
{
	ammo_drop = { 450, 450 };
	clips_drop = { 450, 450 };
	collision = { 0, 0 };
}
void ammo::draw_clips()
{
	DrawCircleV(clips_drop, 20, YELLOW);
	DrawRectangle(clips_drop.x + collision.x - 20, clips_drop.y + collision.y - 25, 40, 40, ORANGE);

}