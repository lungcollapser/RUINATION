#pragma once

#ifndef ENTITY_H
#define ENTITY_H


#include "include.h"


struct entity
{
	void init_entity(uint16 ent_id, component_lists* components, entity_transform* position, entity_health health);
	void draw_entity(uint16 ent_id, v2 ent_position, float radius, Color color, entity_health health);
	void update_entity_health(uint16 ent_id, component_lists* components, entity_health health);
	void kill_entity(uint16 ent_id, component_lists* components);
};

struct entity_transform
{
	uint16 player_id;
	uint16 enemy_id;

	bool active;
};
struct entity_health
{
	uint16 player_id;
	uint16 enemy_id;

	int16 current_health;
	uint32 max_health;
};

struct component_lists
{
	entity_health health_components[100];
	entity_transform transform_components[100];

	uint16 total_health_components;
	uint16 total_transform_components;
};

extern uint32 entities;


#endif