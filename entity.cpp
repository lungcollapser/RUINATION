#include "entity.h"

extern uint16 entities = 0;
extern uint16 player_id = 0;
extern uint16 enemy_id = 1;
extern uint16 weapon_id = 2;
extern uint16 project_weapon_id = 3;
extern uint16 bullet_id = 4;

void CreateEntity(uint16 ent_id, component_lists* component)
{
	ent_id = entities++;

	component->total_health_component++;
	component->total_transform_component++;
	component->total_item_component++;
	component->total_bullet_component++;

}
void DrawEntity(uint16 ent_id, component_lists* component)
{
	if (component->health_component[ent_id].current_health > 0)
	{
		DrawCircleV(component->transform_component[ent_id].ent_position, component->transform_component[ent_id].radius, component->transform_component[ent_id].color);
	}

}
void DrawBullet(uint16 ent_id, component_lists* component)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (component->bullet_component[i].active)
		{
			DrawCircleV(component->transform_component[i].ent_position + component->transform_component[player_id].ent_position, component->transform_component[i].radius, component->transform_component[i].color);
		}
	}
}
void UpdateEntityMovement(uint16 ent_id, component_lists* component)
{
	v2 direction = { 0.0f, 0.0f };

	if (IsKeyDown(KEY_D))
	{
		direction.x++;
	}
	if (IsKeyDown(KEY_A))
	{
		direction.x--;
	}
	if (IsKeyDown(KEY_W))
	{
		direction.y--;
	}
	if (IsKeyDown(KEY_S))
	{
		direction.y++;
	}

	v2 velocity = Vector2Scale(Vector2Normalize(direction), component->transform_component[ent_id].movement_speed * GetFrameTime());
	component->transform_component[ent_id].ent_position = Vector2Add(component->transform_component[ent_id].ent_position, velocity);
}

void UpdateEntityWeapon(uint16 ent_id, component_lists* component)
{

}
void UpdateEntityProjectWeapon(uint16 ent_id, component_lists* component)
{
	component->transform_component[ent_id].ent_position = GetMousePosition() + component->transform_component[player_id].ent_position;
}
void UpdateEntityBullet(uint16 ent_id_one, uint16 ent_id_two, component_lists* component)
{

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!component->bullet_component[i].active)
			{
				component->bullet_component[i].active = true;
				component->transform_component[i].bullet_velocity = Vector2MoveTowards(component->transform_component[i].ent_position, component->transform_component[project_weapon_id].ent_position, 25);
				break;
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (component->bullet_component[i].active)
		{
			component->transform_component[i].ent_position += component->transform_component[i].bullet_velocity;
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

void UpdateEntityHealth(uint16 ent_id, component_lists* component, entity_health health)
{
	if (health.current_health <= 0)
	{
		KillEntity(health.entity_id, component);
	}
}
void KillEntity(uint16 ent_id, component_lists* component)
{

	ent_id = entities--;

	component->total_health_component--;
	component->total_transform_component--;
	component->total_item_component--;
	component->total_bullet_component--;
}


