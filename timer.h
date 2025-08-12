#pragma once
#include "include.h"

struct timer
{

	uint16 timer_max;
	uint16 timer_left;
	uint16 timer_state_choice;
};
enum timer_state
{
	timer_running = 1,
	timer_stop = 2,
	timer_paused = 3
};

void draw_timer(v2 player_object);
void alloc();
void dealloc();