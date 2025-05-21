#pragma once
#include "include.h"
#include "bullet.h"
#include "player.h"

class weapon
{
private:
	bool is_reloading;
public:
	weapon();
	~weapon();
	void draw(Vector2 player_object);
	void fire(weapon &curr_weapon);
	void take_input();
	void change_weapon();
	void reload();
	int circle_offset;
	int bullet_speed;
	int bullet_amount;
	int clips;
	int current_clips;
	Vector2 weapon_reticle;
	std::vector<bullet> bullets;

};