#pragma once
#include "weapon.h"
#include "include.h"


class revolver : weapon
{
private:
	bool active;

public:
	revolver();
	~revolver();
	void draw();
	void reload();
};