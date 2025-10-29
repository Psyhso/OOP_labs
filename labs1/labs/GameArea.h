#pragma once
#include "Cell.h"
#include "Coords.h"
#include <vector>


class Player;
class Enemy;
class Human;

class GameArea {
private:	
	int height;
	int width;
	std::vector<std::vector<Cell>> area; 

public:
	GameArea(int h, int w) : height(h), width(w), area(h, std::vector<Cell>(w)) {}
    // Конструктор копирования
    GameArea(const GameArea& other)
        : height(other.height), width(other.width), area(other.area) {
    }

    // Оператор присваивания с копированием
    GameArea& operator=(const GameArea& other) {
        if (this != &other) {
            height = other.height;
            width = other.width;
            area = other.area; // Глубокая копия через оператор= вектора
        }
        return *this;
    }

    // Конструктор перемещения
    GameArea(GameArea&& other) noexcept
        : height(std::exchange(other.height, 0)),
        width(std::exchange(other.width, 0)),
        area(std::move(other.area)) {
    }

    // Оператор присваивания с перемещением
    GameArea& operator=(GameArea&& other) noexcept {
        if (this != &other) {
            height = std::exchange(other.height, 0);
            width = std::exchange(other.width, 0);
            area = std::move(other.area);
        }
        return *this;
    }
	void set_human_in_cell(Coords object_coords, Human* human);
	void set_building_in_cell(Coords object_coords, Building* building);
	CellType get_cell_type(Coords coords);
	double get_coast_exp_enemy(Coords coords);
	void fill_area(Player* player, std::vector<Enemy*> enemyes, std::vector<Building*> buildings);
	void print_area();
	void move_human(Coords from, Coords to, Human* human);
	bool player_or_enemy(Coords coords);
	bool attack(Human* human, Coords enemy_coords, double input_damage);
	std::string can_move_to(Coords move_coords);
	bool is_valid_coords(Coords& coord);

};