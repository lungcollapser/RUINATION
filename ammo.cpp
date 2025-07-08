#include "ammo.h"

//TODO: narrow position down so the code is less redudant. having to write that its the ammo drop position twice on ruination.cpp. once for draw and twice for collision. unnecessary 
//TPDP: MAKE AMMO AND CLIPS ONE OVERALL THING INSTEAD OF HAVING TWO DRAWS AND TWO DIFFERENT TYPES

ammo::ammo()
{
	ammo_drop = { 0, 0 };
}
void ammo::draw(Vector2 position)
{
	srand(time(0));

	ammo_choices_rand = rand() % 1;

	switch (ammo_choices_rand)
	{
	case bullets : DrawCircleV(ammo_drop, 10, PURPLE); ammo_drop = position; break;
	case clips: DrawCircleV(ammo_drop, 10, YELLOW); ammo_drop = position; break;

		if (current_ammo_state == picked_up)
		{
			break;
		}
	}
}
void ammo::update()
{
}
Rectangle ammo::get_rectangle(Vector2 position)
{
	return Rectangle{ position.x - 25, position.y - 25, 50, 50 };
}
