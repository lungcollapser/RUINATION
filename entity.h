/*#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "include.h"

struct entity
{
	entity_transform s_transform;
	entity_name s_entity_name;
};

struct entity_transform
{
	bool active;
	v2 position;
	uint16 speed;
};
enum entity_name
{
	ent_player,
	ent_enemy,
	ent_bullet,
};

struct entity_init
{
	void init();
};
struct entity_draw
{
	void draw();
};

#endif*/