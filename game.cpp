#include "game.h"
#include "player.h"

player player_game;

game::game()
{
	run = true;
}
game::~game()
{
	
}
void game::update()
{
	for (auto& gun : player_game.guns)
	{
		gun.updates();
	}
}

void game::draw()
{
	player_game.draw();

	for (auto& gun : player_game.guns)
	{
		gun.draw();
	}
}
void game::handle_input()
{
	if (IsKeyDown(KEY_D))
	{
		player_game.move_right();
	}
	else if (IsKeyDown(KEY_A))
	{
		player_game.move_left();
	}
	else if (IsKeyDown(KEY_W))
	{
		player_game.move_up();
	}
	else if (IsKeyDown(KEY_S))
	{
		player_game.move_down();
	}

	if (IsKeyDown(KEY_LEFT_SHIFT))
	{
		player_game.walk();
	}
	if (IsKeyPressed(KEY_R))
	{
		player_game.reload();
	}


	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		player_game.shoot();
	}
}
