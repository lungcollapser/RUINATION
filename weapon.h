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
	void fire(Vector2 &weapon_reticle, Vector2 &center_position, int bullet_speed);
	void take_input();
	void draw(Vector2 &player_object);
	std::vector<bullet>& get_bullets(weapon *weapon);
	Vector2 weapon_reticle;
	std::vector<bullet> bullets;
	int bullet_speed, bullet_amount, max_bullets, clips, current_clips;
};