#include "ammo.h"

//TODO: narrow position down so the code is less redudant. having to write that its the ammo drop position twice on ruination.cpp. once for draw and twice for collision. unnecessary 
//TPDP: MAKE AMMO AND CLIPS ONE OVERALL THING INSTEAD OF HAVING TWO DRAWS AND TWO DIFFERENT TYPES

ammo::ammo()
{
	ammo_drop = { 0, 0 };
}
void ammo::draw(v2 position)
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
bool ammo::collision(Rectangle collision_one, Rectangle collision_two)
{
	if (CheckCollisionRecs(collision_one, collision_two))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void ammo::update(Rectangle rec1, Rectangle rec2, weapon* current_weapon)
{
    //TODO: make the item drop choice global for all things that can be destroyed have the chance to drop items.
    bool ammo_collision = collision(rec1, rec2);


    if (ammo_collision && ammo_choices == clips)
    {
        current_weapon->clips += 1;
        current_ammo_state = picked_up;
        std::cout << "picked up";
    }

    if (ammo_collision && current_weapon->bullet_amount < current_weapon->max_bullets && ammo_choices == bullets)
    {
        current_weapon->bullet_amount = current_weapon->max_bullets;
        current_ammo_state = picked_up;
        std::cout << "picked up";

    }
}
Rectangle ammo::get_rectangle(v2 position)
{
	return Rectangle{ position.x - 25, position.y - 25, 50, 50 };
}
