#include "game.h"

player player_game;
weapon weapon_game;
camera camera_game;


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
	camera_game.update();

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		weapon_game.fire();
	}

	player_game.take_input();
	camera_game.take_input();
}

void game::draw()
{
	player_game.draw();
	weapon_game.draw(player_game.player_object);

	for (auto& bullet : weapon_game.bullets)
	{
		bullet.draw(player_game.player_object);
	}
}

