#pragma once
#include "bullet.h"
#include "player.h"
#include "include.h"


class weapon
{
private:
	bool is_reloading;
protected:
	int bullet_speed;
	int bullet_left;
public:
	weapon();
	~weapon();
	void draw(Vector2& player_object);
	void fire();
	void take_input();
	void weapon_attributes();
	void reload();
	int bullet_amount;
	int circle_offset;
	Vector2 weapon_reticle;
	std::string weapons[4];
	std::string current_weapon;
	std::vector<bullet> bullets;

};