#include "timer.h"

void draw_timer(v2 player_object)
{
	timer *max_timer = (timer*) malloc(sizeof(uint16));

	if (max_timer)
	{
		DrawText(TextFormat("Time Left: ", max_timer->timer_max), player_object.x - 50, player_object.y - 50, 50, ORANGE);
	}

	
	free(max_timer);

	
}