#include "Coords.h"
#pragma once

class Human {
protected:
	double health;
	double damage;
	Coords coords;
public:
	virtual void moving();
	virtual void attack();
};