#pragma once

#ifndef ENTITY_H
#define ENTITY_H
#include "include.h"

#define MAX_BULLETS 50



struct entity
{
	
};

struct entity_transform
{
	uint16 entity_id;

	v2 ent_position;
	uint16 movement_speed;
	float radius;
	Color color;
};
struct entity_health
{
	uint16 entity_id;

	int16 current_health;
	uint32 max_health;
};
struct entity_item
{
	uint16 entity_id;

	bool active;
	uint16 durability;
};
struct entity_bullet
{
	uint16 entity_id;

	bool active;

	v2 bullet_position;
	v2 bullet_velocity;

	uint16 ammunition;
	uint16 max_ammunition;
	uint16 damage;

	float radius;
	Color color;
};
struct component_lists
{
	entity_health health_component[100];
	entity_transform transform_component[100];
	entity_item item_component[100];
	entity_bullet bullet_component[MAX_BULLETS];

	uint16 total_health_component;
	uint16 total_transform_component;
	uint16 total_item_component;
	uint16 total_bullet_component;
};


extern uint16 entities;
extern uint16 player_id;
extern uint16 enemy_id;
extern uint16 project_weapon_id;
extern uint16 bullet_id;

void CreateEntity(uint16 ent_id, component_lists* component);
void DrawEntity(uint16 ent_id, component_lists* component);
void DrawBullet(uint16 ent_id, component_lists* component);
void UpdateEntityMovement(uint16 ent_id, component_lists* component);
void UpdateEntityBullet(uint16 ent_id_one, uint16 ent_id_two, component_lists* component);
void UpdateEntityWeapon(uint16 ent_id, component_lists* component);
void UpdateEntityProjectWeapon(uint16 ent_id, component_lists* component);
void UpdateEntityHealth(uint16 ent_id, component_lists* component, entity_health health);
void KillEntity(uint16 ent_id, component_lists* component);

#endif