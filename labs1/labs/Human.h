#pragma once

#include "Coords.h"
#include "GameArea.h"
#include <string>


class Human {
protected:
	double health;
	double damage;
	Coords coords;
public:
	Coords get_coords();
	Coords set_coords(int x, int y);
	bool moving(std::string direction, GameArea& gamearea);
	void attack();
};