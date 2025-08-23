#include "bullet.h"

bullet* bullet_main = nullptr;

void init_b(v2 player_object)
{
	bullet_main = (bullet*)malloc(sizeof(bullet));

	if (bullet_main == NULL)
	{
		std::cout << "player alloc failed!";
		return;
	}

	bullet_main->bullet_radius = 10;
	bullet_main->active = false;
	bullet_main->fire_position = { 0, 0 };

}
void free_b()
{
	free(bullet_main);
}
void draw_b(v2 position, uint16 bullet_amount)
{
	
	if (bullet_main->active)
	{
		for (int bullets = 0; bullets < bullet_amount; bullets++)
		{
			DrawCircleV(bullet_main->fire_position + position, bullet_main->bullet_radius, BLUE);
			DrawRectangleLines(bullet_main->fire_position.x + position.x, bullet_main->fire_position.y + position.y, 15, 15, YELLOW);
		}
	}
	
}
void update_b(v2 weapon_reticle, v2 center_position, uint16 bullet_amount)
{

	v2 change_vector = Vector2Scale(Vector2Normalize(bullet_main->fire_position), bullet_main->bullet_speed * GetFrameTime());
	bullet_main->fire_position = Vector2Add(bullet_main->fire_position, change_vector);

	bullet_main->fire_position = Vector2MoveTowards(weapon_reticle, center_position, 10);

	if (bullet_main->fire_position.x > GetScreenWidth(), bullet_main->fire_position.y > GetScreenHeight())
	{
		bullet_main->active = false;
	}
	else
	{
		bullet_main->active = true;
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
Rectangle get_rectangle_bullet(v2 position)
{
	return Rectangle{ bullet_main->fire_position.x + position.x, bullet_main->fire_position.y + position.y, 15, 15 };
}
