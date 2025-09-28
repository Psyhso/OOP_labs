#include "Cell.h"
#include <vector>
#pragma once

class GameArea {
private:	
	int height;
	int width;
	std::vector<std::vector<Cell>> area;

public:
	GameArea(int h, int w) : height(h), width(w), area(h, std::vector<Cell>(w)) {}
	void fill_area();
};