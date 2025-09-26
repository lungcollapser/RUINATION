#pragma once

#ifndef ENTITY_H
#define ENTITY_H


#include "include.h"


struct entity
{
	
};

struct entity_transform
{
	uint16 entity_id;

	v2 ent_position;
	uint16 speed;
	float radius;
	Color color;
};
struct entity_health
{
	uint16 entity_id;

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

extern uint16 entities;
extern uint16 player_id;
extern uint16 enemy_id;
extern uint16 weapon_id;


void CreateEntity(uint16 ent_id, component_lists* components);
void DrawEntity(uint16 ent_id, component_lists* components);
void UpdateEntityMovement(uint16 ent_id, component_lists* component);
void UpdateEntityBullet(uint16 ent_id, component_lists* component);
void UpdateEntityHealth(uint16 ent_id, component_lists* components, entity_health health);
void KillEntity(uint16 ent_id, component_lists* components);

#endif