#pragma once
#include "weapon.h"
#include "include.h"


class revolver : weapon
{
private:
	bool active;

public:
	revolver(int bm, int bs);
	~revolver();
	void draw();
	void reload();
};