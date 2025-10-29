#pragma once
#include "Building.h"
#include "Enemy.h"


class EnemyBuilding : public Building {
private:
	int count_step_spawn;
	int step;
public:
	EnemyBuilding(int h, Coords crd, int c) : Building(h, crd), count_step_spawn(c), step(0) {}
	void plus_step(GameArea& gamearea);
	void spawn_enemy(GameArea& gamearea);
	Coords find_nearest_free_cell(GameArea& gamearea);
};

