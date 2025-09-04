#include "bullet.h"

bullet bullets[MAX_BULLETS] = { 0 };

void init_b(v2 player_object)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		bullets[i].active = false;
		bullets[i].fire_position = { player_object };
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
				bullets[i].speed = Vector2MoveTowards(bullets[i].fire_position, weapon_reticle, 25);
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

