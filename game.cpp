#include "game.h"

player player_game;
weapon weapon_game;


game::game()
{
	run = true;
}
game::~game()
{
	
}
void game::update()
{
	for (auto& bullet : weapon_game.bullets)
	{
		bullet.update_position();
	}
}

void game::draw()
{
	player_game.draw();
	weapon_game.draw(player_game.player_object);

	for (auto& bullet : weapon_game.bullets)
	{
		bullet.draw();
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
		weapon_game.fire();
	}
}
