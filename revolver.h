#pragma once
#include "weapon.h"


class revolver : public weapon
{
private:
	bool active;

public:
	revolver();
	~revolver();
	void draw();
};