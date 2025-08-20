#pragma once

#ifndef REVOLVER_H
#define REVOLVER_H

#include "weapon.h"

struct revolver : public weapon
{
	void init_rev(revolver* revolver_init                                 );
	void free_rev(revolver* revolver);
};

local_persist revolver* revolver_main;


#endif