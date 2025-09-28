#pragma once
#include <iostream>
#include <string>
#include <utility>
#include "Human.h"
#include "Tower.h"


class Cell {
private:
	std::string type = "Basic";
	std::pair<Human*, Tower*> object;
public:
	Cell() : object(nullptr, nullptr) {}
	std::string get_type();
	std::string is_empty();
	void set_human(Human* human);
	void set_tower(Tower* tower);
	Human* get_human();
	Tower* get_tower();
	void clear();
};
