#include "ammo.h"

bullet bullets[MAX_BULLETS] = { 0 };

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

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].active)
		{

			DrawCircleV(bullets[i].fire_position + position, 10, YELLOW);
			DrawRectangle(bullets[i].fire_position.x + position.x, bullets[i].fire_position.y + position.y, 15, 15, ORANGE);
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
bool collision_detection(Rectangle rec1, Rectangle rec2)
{
	if (CheckCollisionRecs(rec1, rec2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

