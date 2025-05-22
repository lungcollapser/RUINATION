#pragma once
#include "include.h"
#include "bullet.h"

class weapon
{
private:
	bool is_reloading;
protected:
	
public:
	weapon();
	~weapon();
	void draw(Vector2 &player_object);
	void fire(Vector2 &player_object);
	void take_input();
	void change_weapon();
	void reload();
	Vector2 weapon_reticle;
	std::vector<bullet> bullets;
	int bullet_speed;
	int bullet_amount;
	int clips;
	int current_clips;


};