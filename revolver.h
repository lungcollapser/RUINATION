#pragma once
#include "weapon.h"


class revolver : public weapon
{
private:
	bool active;

public:
	revolver();
	~revolver();
	void draw(Vector2 player_object);
	Vector2 get_revolver_reticle();

};