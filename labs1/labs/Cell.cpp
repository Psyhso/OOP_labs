#include "Cell.h"
#include "Player.h"
#include "Enemy.h"
#include "Building.h"

CellType Cell::get_type()
{
    return type;
}

std::string Cell::is_empty()
{
    if (!(object.first) && !(object.second)) {
        return std::string("Empty");
    }
    else if (object.first && !(object.second)) {
        return std::string("Human");
    }
    else {
        return std::string("Building");
    }
}

void Cell::set_human(Human* human)
{
    if (this->is_empty() == "Empty") {
        object.first = human;
    }
}

void Cell::set_building(Building* tower)
{
    if(this->is_empty() == "Empty") {
        object.second = tower;
    }
}

void Cell::set_type(CellType new_type)
{
    type = new_type;
}

Human* Cell::get_human()
{
    return object.first;
}

Building* Cell::get_building()
{
    return object.second;
}

bool Cell::player_or_enemy() // Вернет true, если Player иначе Enemy
{
    Human* human = object.first;
    if (Player* player = dynamic_cast<Player*>(human)) {
        std::cout << "Это Player!\n";
        return true;
    }
    else if (Enemy* enemy = dynamic_cast<Enemy*>(human)) {
        std::cout << "Это Enemy!\n";
        return false;
    }
    else {
        return false; //Ошибку запихать
    }
}

void Cell::clear() {
    object.first = nullptr;
    object.second = nullptr;
}

std::string Cell::get_type_string() {
    switch (type) {
    case CellType::BASIC: return "Basic";
    case CellType::BLOCKED: return "Blocked";
    case CellType::SLOW: return "Slow";
    default: return "Unknown";
    }
}