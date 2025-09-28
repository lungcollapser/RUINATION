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
		DrawCircle(component->transform_component[ent_id].ent_position.x, component->transform_component[ent_id].ent_position.y, component->transform_component[ent_id].radius, component->transform_component[ent_id].color);
	}

	if (component->bullet_component[bullet_id].active)
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			component->bullet_component[i].active = false;
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

	v2 velocity = Vector2Scale(Vector2Normalize(direction), component->transform_component[ent_id].speed * GetFrameTime());
	component->transform_component[ent_id].ent_position = Vector2Add(component->transform_component[ent_id].ent_position, velocity);
}

void UpdateEntityWeapon(uint16 ent_id, component_lists* component)
{

}
void UpdateEntityProjectWeapon(uint16 ent_id, component_lists* component)
{
	component->transform_component[ent_id].ent_position = GetMousePosition() + component->transform_component[player_id].ent_position;
}
void UpdateEntityBullet(uint16 ent_id, component_lists* component)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (!component->bullet_component.active)
			{
				component->bullet_component.active = true;
				component->bullet_component.speed = Vector2MoveTowards(component->bullet_component.fire_position, position, 25);
				break;
			}
		}
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (component->bullet_component.active)
		{
			component->bullet_component.fire_position += component->bullet_component.speed;
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
}


