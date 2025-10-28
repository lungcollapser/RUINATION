#pragma once

#ifndef ENTITY_H
#define ENTITY_H
#include "include.h"

#define MAX_BULLETS 100


struct entity_transform
{
	uint16 entity_id;

	bool active;

	v2 ent_position;
	v2 ent_velocity;

	Rectangle ent_collision;

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
struct entity_item
{
	uint16 entity_id;

	bool active;
	uint16 durability;
};
struct entity_bullet
{
	uint16 entity_id;
	uint16 transform_id;

	bool active;

	uint16 ammunition;
	uint16 max_ammunition;
	uint16 damage;
};
struct entity_camera
{
	uint16 entity_id;

	Camera2D entity_cam;
};

struct component_lists
{
	entity_health health_component[100];
	entity_transform transform_component[500];
	entity_item item_component[100];
	entity_bullet bullet_component[MAX_BULLETS];
	entity_camera camera_component[100];

	uint16 total_health_component;
	uint16 total_transform_component;
	uint16 total_item_component;
	uint16 total_bullet_component;
	uint16 total_camera_component;
	uint16 total_collision_component;

};


extern uint16 entities;
extern uint16 player_id;
extern uint16 enemy_id;
extern uint16 project_weapon_id;
extern uint16 bullet_id;
extern uint16 camera_id;

uint16 AddEntity(uint16 ent_id);
uint16 AddComponents(uint16 component_type);
void DrawEntity(uint16 ent_id, v2 position_one, v2 position_two, float radius, Color color, component_lists* component);
void DrawCollision(uint16 ent_id, Rectangle collision, v2 position_two, component_lists* component);
void UpdateEntityMovement(uint16 ent_id, component_lists* component);
void UpdateEntityBullet(uint16 ent_id, uint16 transform_id, component_lists* component);
void UpdateEntityWeapon(uint16 ent_id, component_lists* component);
void UpdateEntityProjectWeapon(uint16 ent_id, component_lists* component);
void UpdateEntityHealth(uint16 ent_id, component_lists* component, entity_health health);
void UpdateEntityCollision(uint16 ent_id, component_lists* component, v2  circle_one, float radius_one);
void UpdateEntityCamera(uint16 ent_id, component_lists* component);
void KillEntity(uint16 ent_id, component_lists* component);

#endif