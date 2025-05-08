#pragma once
#include "bullet.h"
#include "player.h"
#include "include.h"


class weapon
{
private:
	bool is_reloading;

public:
	enum weapon_types
	{
		revolver, repeater
	};
	weapon();
	weapon(weapon_types weapons, int bull_speed, int bull_amount);
	~weapon();
	void draw(Vector2 player_object);
	void fire();
	void take_input();
	void change_weapon(weapon_types new_weapon);
	void reload();
	int circle_offset;
	int bullet_speed;
	int bullet_amount;
	Vector2 weapon_reticle;
	weapon_types current_weapon;
	std::vector<bullet> bullets;

};