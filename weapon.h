#pragma once
#include "include.h"
#include "player.h"

class weapon
{
private:
	bool is_reloading;
	std::string current_weapon;
public:
	weapon();
	~weapon();
	void handle_input();
	void get_weapon_stats();
	void set_weapon_stats();
	std::string get_current_weapon(std::string current_weapon);
};