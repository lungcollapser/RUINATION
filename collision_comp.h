#pragma once
#include "include.h"

struct collision_comp
{
	Rectangle rec1;
	Rectangle rec2;
};
void draw_collision(Rectangle collision);
bool collision_detection(Rectangle rec1, Rectangle rec2);