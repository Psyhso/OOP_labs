#pragma once
#include "Human.h"



class Enemy : public Human {
private:
	double coast_exp;
public:
	Enemy(double h, double d, Coords coords) : Human(h, d, coords), coast_exp(h / 2) {}
	bool attack(Coords enemy_coords, GameArea& gamearea);
	double get_coast_exp();
};