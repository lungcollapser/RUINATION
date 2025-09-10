#pragma once
#include "include.h"

struct collision_comp
{
	Rectangle collision_rec;
};

bool collision_detection(Rectangle collision_one, Rectangle collision_two)
{
	if (CheckCollisionRecs(collision_one, collision_two))
	{
		return true;
	}
	else
	{
		return false;
	}
}