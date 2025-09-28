#pragma once
#include "Cell.h"
#include "Coords.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>


class GameArea {
private:	
	int height;
	int width;
	std::vector<std::vector<Cell>> area; 

public:
	GameArea(int h, int w) : height(h), width(w), area(h, std::vector<Cell>(w)) {}
	void set_human_in_cell(Coords object_coords, Human* human);
	void set_tower_in_cell(Coords object_coords, Tower* tower);
	void fill_area(Player* player, std::vector<Enemy*> enemyes);
	void move_human(Coords from, Coords to, Human* human);
	std::string can_move_to(Coords move_coords);

};