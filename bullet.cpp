#include "bullet.h"

extern bullet bullets[MAX_BULLETS] = { 0 };

void init_b()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].active = false;
	}
}
void draw_b(v2 position)
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

void update_b(v2 weapon_reticle, v2 center_position)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!bullets[i].active)
			{
				bullets[i].active = true;
				bullets[i].fire_position = { center_position };
				bullets[i].speed.x = 6.0;
				bullets[i].speed.y = 6.0;
			}

		}

	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].active)
		{
			bullets[i].fire_position.x += bullets[i].speed.x;
			bullets[i].fire_position.y -= bullets[i].speed.y;
		}


		if (bullets[i].fire_position.x > screen_size_x || bullets[i].fire_position.y > screen_size_y)
		{
			bullets[i].active = false;
		}
	}

}
bool bullet_collision(Rectangle collision_one, Rectangle collision_two)
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

