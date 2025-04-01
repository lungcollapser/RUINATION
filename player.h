#pragma once
#include "raylib.h"
#include "raymath.h"
#include "gun.h"
#include <vector>

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
	//vector for gun/bullets. used for shoot method.
	std::vector<gun> guns;
	//player attributes
	Vector2 player_object;
	int player_speed;
	int bullets;






};