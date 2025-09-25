#include "entity.h"

extern uint16 entities = 0;
extern uint16 player_id = 0;
extern uint16 enemy_id = 0;

void init_entity(component_lists* components)
{
	player_id = entities++;
	enemy_id = entities++;

	components->total_health_components++;
	components->total_health_components++;
	components->total_transform_components++;
	components->total_transform_components++;

	components->transform_components[player_id] = { player_id, 100, 100, 40, WHITE };
	components->transform_components[enemy_id] = { enemy_id, 200, 400, 20, RED };

	components->health_components[player_id] = { player_id, 20, 20 };
	components->health_components[enemy_id] = { enemy_id, 20, 20 };



}
void draw_entity(component_lists* components)
{
	if (components->health_components[player_id].current_health > 0)
	{
		DrawCircle(components->transform_components[player_id].ent_position.x, components->transform_components[player_id].ent_position.y, components->transform_components[player_id].radius, components->transform_components[player_id].color);
	}
}
void update_entity_health(uint16 ent_id, component_lists* components, entity_health health)
{
	if (health.current_health <= 0)
	{
		kill_entity(ent_id, components);
	}
}
void kill_entity(uint16 ent_id, component_lists* components)
{

	uint16 id = entities--;

	ent_id = id;
	components->health_components[id];
	components->total_health_components--;
	components->transform_components[id];
	components->total_transform_components--;
}


