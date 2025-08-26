#include "bullet.h"

bullet bullets[MAX_BULLETS];

void init_b()
{
	
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
void shoot_b(v2 weapon_reticle, v2 center_position, uint16 bullet_speed)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{

		if (!bullets[i].active)
		{
			bullets[i].active = true;
			bullets[i].fire_position = center_position;
			bullets[i].velocity = bullet_speed;
			break;
		}


	}
	
}
void update_b(v2 weapon_reticle, v2 center_position, uint16 bullet_speed)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets[i].active)
		{
			bullets[i].fire_position = Vector2MoveTowards(center_position, weapon_reticle, 1);
		}


		if (bullets[i].fire_position.x > 0 || bullets[i].fire_position.y > 0)
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

