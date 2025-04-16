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
		bullet.draw(player_game.player_object);
	}
}
void game::handle_input()
{

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		weapon_game.fire();
	}
}
