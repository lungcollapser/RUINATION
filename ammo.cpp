#include "ammo.h"

bullet bullets[MAX_BULLETS] = { 0 };
ammo_system ammo;

void init_ammo(v2 position)
{

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].active = false;
		bullets[i].fire_position = { position };
		bullets[i].weapon_lock = true;
	}
}
void draw_ammo(v2 position)
{
	DrawRectangle(ammo.ammo_drop.x, ammo.ammo_drop.y, 10, 10, BLUE);

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].active)
		{

			DrawCircleV(bullets[i].fire_position + position, 10, YELLOW);
			DrawRectangle(bullets[i].fire_position.x + position.x, bullets[i].fire_position.y + position.y, 10, 10, WHITE);

		}
	}

}

void update_ammo(v2 position_one, v2 position_two)
{


	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!bullets[i].active && bullets[i].weapon_lock)
			{
				bullets[i].active = true;
				bullets[i].speed = Vector2MoveTowards(bullets[i].fire_position, position_one, 25);
				break;
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].active)
		{
			bullets[i].fire_position += bullets[i].speed;
		}

		/* NEEDS TO BE OPTIMIZED!!!
		if (bullets[i].fire_position.x > screen_size_x || bullets[i].fire_position.y > screen_size_y)
		{
			bullets[i].active = false;
			std::cout << "inactive";
		}
		*/
	}

}


