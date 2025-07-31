#pragma once
#include "include.h"

#ifndef PLAYER_H
#define PLAYER_H

enum entity_type
{
	entity_type_pc = 1,
	entity_type_npc = 2,

};
struct entity_stats
{
	uint8 entity_stat_assign();

	uint8 entity_choice;
	uint8 health;
	uint8 speed;
	v2 position;

};
struct entity_draw
{
	void draw(v2 position);

};
#endif