#include "timer.h"

void timer::draw(v2 player_object)
{
	DrawText(TextFormat("Time Left: ", timer_max), player_object.x - 50, player_object.y - 50, 50, ORANGE);

}