#pragma once
#include <iostream>
#include <string>
#include <utility>


class Human;
class Building;

enum class CellType {
	BASIC,      // Обычная клетка
	BLOCKED,    // Непроходимое препятствие
	SLOW       // Замедляющая клетка
};

class Cell {
private:
	CellType type = CellType::BASIC;
	std::pair<Human*, Building*> object;
	bool is_passable = true;
public:
	Cell() : object(nullptr, nullptr) {}
	CellType get_type();
	Human* get_human();
	Building* get_building();
	std::string get_type_string();
	std::string is_empty();
	void set_human(Human* human);
	void set_building(Building* building);
	void set_type(CellType new_type);
	void clear();
	bool player_or_enemy();
};
