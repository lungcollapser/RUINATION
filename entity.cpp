#include "entity.h"

extern uint16 entities = 0;
extern uint16 player_id = 0;
extern uint16 enemy_id = 1;
extern uint16 weapon_id = 2;

void CreateEntity(uint16 ent_id, component_lists* components)
{
	ent_id = entities++;

	components->total_health_components++;
	components->total_transform_components++;

}
void DrawEntity(uint16 ent_id, component_lists* components)
{
	if (components->health_components[ent_id].current_health > 0)
	{
		DrawCircle(components->transform_components[ent_id].ent_position.x, components->transform_components[ent_id].ent_position.y, components->transform_components[ent_id].radius, components->transform_components[ent_id].color);
	}
}
void UpdateEntityMovement(uint16 ent_id, component_lists* components)
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

	v2 velocity = Vector2Scale(Vector2Normalize(direction), components->transform_components[ent_id].speed * GetFrameTime());
	components->transform_components[ent_id].ent_position = Vector2Add(components->transform_components[ent_id].ent_position, velocity);
}
void UpdateEntityBullet(uint16 ent_id, component_lists* component)
{

}
void UpdateEntityHealth(uint16 ent_id, component_lists* components, entity_health health)
{
	if (health.current_health <= 0)
	{
		KillEntity(health.entity_id, components);
	}
}
void KillEntity(uint16 ent_id, component_lists* components)
{

	ent_id = entities--;

	components->total_health_components--;
	components->total_transform_components--;
}


