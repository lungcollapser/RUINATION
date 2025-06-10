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
	void fire(Vector2 &center_position);
	void take_input();
	void draw(Vector2 &player_object);
	Vector2 weapon_reticle;
	std::vector<bullet> bullets;
	int bullet_speed;
	int bullet_amount;
	int max_bullets;
	int clips;
	int current_clips;
};