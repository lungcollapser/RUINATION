#pragma once
#include "include.h"

const uint32 MAX_ENTITIES = 5000;
const uint8 MAX_COMPONENTS = 32;

using entity = uint32;
using component_type = uint8;
using signature = std::bitset<MAX_COMPONENTS>;
std::array<signature, MAX_ENTITIES> entity_signatures;


struct entity_manager
{

	std::queue<entity> available_entities;
	uint32 living_entities = 0;

	inline void init_entity()
	{
		for (entity entity_count = 0; entity_count < MAX_ENTITIES; entity_count++)
		{
			available_entities.push(entity_count);
		}
	}

	entity create_entity()
	{
		assert(living_entities < MAX_ENTITIES && "TOO MANY ENTITIES!!!");

		entity id = available_entities.front();
		available_entities.pop();
		living_entities++;

		return id;
	}
	void destroy_entity(entity entity)
	{
		assert(entity < MAX_ENTITIES && "ENTITY OUT OF RANGE!!!");

		//invalidate the destroyed entitys signature. UNDERSTAND THIS!!!
		entity_signatures[entity].reset();

		available_entities.push(entity);
		living_entities--;
	}
	void set_signature(entity entity, signature signature)
	{
		entity_signatures[entity] = signature;
	}
	signature get_signature(entity entity)
	{
		return entity_signatures[entity];
	}
};

enum entity_type
{
	entity_type_pc = 1,
	entity_type_npc = 2,
	entity_type_weapon = 3,
	entity_type_bullets = 4, 

};

struct transform
{
	v2 position;
	v2 scale;
	Color e_color;
};
struct stats
{
	uint32 health;
	uint32 speed;
	uint32 dodge_speed;
	uint32 damage;
};
struct state
{
	enum health_state;
	enum move_state;
};
