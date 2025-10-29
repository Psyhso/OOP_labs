#pragma once
#include "Human.h"


class Player : public Human {
private:
	double experience;
	double experience_for_new_level;
	int level;
	bool melee = true;
public:
	Player(double h, double d, Coords coords) : Human(h, d, coords), experience(0), experience_for_new_level(50), level(1) {}
	bool attack(Coords enemy_coords, GameArea& gamearea);
	void up_level();
	void up_exp(double input_exp);
	double get_exp();
	void change_range();
};
