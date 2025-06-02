#include "ammo.h"

ammo::ammo()
{
	ammo_drop = { 450, 450 };
	clips_drop = { 450, 450 };
}
void ammo::draw_clips()
{
	DrawCircleV(clips_drop, 30, YELLOW);

}