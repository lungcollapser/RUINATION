#include "entity.h"

void entity::init_entity(uint16 ent_id, component_lists* components, entity_transform* position, entity_health health)
{
	uint16 id = entities++;

	ent_id = id;
	components->health_components[id];
	components->total_health_components++;
	components->transform_components[id];
	components->total_transform_components++;


}
void entity::draw_entity(uint16 ent_id, v2 ent_position, float radius, Color color, entity_health health)
{
	if (health.current_health > 0)
	{
		DrawCircle(ent_position.x, ent_position.y, radius, color);
	}
}
void entity::update_entity_health(uint16 ent_id, component_lists* components, entity_health health)
{
	if (health.current_health <= 0)
	{
		kill_entity(ent_id, components);
	}
}
void entity::kill_entity(uint16 ent_id, component_lists* components)
{

	uint16 id = entities--;

	ent_id = id;
	components->health_components[id];
	components->total_health_components--;
	components->transform_components[id];
	components->total_transform_components--;
}


