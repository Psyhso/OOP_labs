#pragma once
#include "Coords.h"

class Building {
protected:
	double health;
	Coords coords;
public:
	Building(int h, Coords crd) : health(h), coords(crd) {}
	Coords get_coords();
};