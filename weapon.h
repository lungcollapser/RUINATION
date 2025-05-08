#pragma once
#include "bullet.h"
#include "player.h"
#include "revolver.h"
#include "include.h"


class weapon
{
private:
	bool is_reloading;
protected:
	int min_bullets;
	int max_bullets;
public:
	enum weapon_types
	{
		revolver, repeater
	};
	weapon();
	~weapon();
	void draw(Vector2& player_object);
	void fire();
	void take_input();
	void change_weapon(weapon_types new_weapon);
	void reload();
	int bullet_speed;
	int circle_offset;
	Vector2 weapon_reticle;
	weapon_types current_weapon;
	std::vector<bullet> bullets;

};