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
	//vector for gun/bullets. used for shoot method.
	std::vector<gun> guns;
	//player attributes
	Vector2 player_object;
	Vector2 player_reticle;
	int player_speed;





};