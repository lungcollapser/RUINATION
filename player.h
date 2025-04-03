#pragma once
#include "revolver.h"
#include "bullet.h"
#include "weapon.h"
#include "include.h"


class player
{
public:
	//constructor
	player();
	//destructor
	~player();
	//player actions
	void draw();
	void shoot();
	int take_damage(float damage);
	//player movement
	void move_right();
	void move_left();
	void move_up();
	void move_down();
	void walk();
	void reload();
	//vector array container for bullets. used for shoot method.
	std::vector<bullet> bullets;
	//player attributes
	Vector2 player_object;
	int player_speed;







};