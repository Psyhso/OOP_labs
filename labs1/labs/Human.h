#pragma once

#include "Coords.h"
#include <string>
#include "GameError.h"


class GameArea;

class Human {
protected:
	double health;
	double damage;
	Coords coords;
	bool stunned = false;
public:
	Human(double h, double d, Coords coords) : health(h), damage(d), coords(coords) {}
	Coords get_coords();
	double get_health();
	double get_damage();
	void set_coords(int x, int y);
	virtual bool attack(Coords enemy_coords, GameArea& gamearea) = 0;
	bool moving(std::string direction, GameArea& gamearea);
	void take_damage(double input_damage);
	double damage_calculation();
	void set_stunned(bool new_stunned);
	bool stunned_or_not();
};