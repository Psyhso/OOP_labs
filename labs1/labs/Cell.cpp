#include "Cell.h"

std::string Cell::get_type()
{
    return type;
}

std::string Cell::is_empty()
{
    if (!(object.first && object.second)) {
        return std::string("Empty");
    }
    else if (object.first && !(object.second)) {
        return std::string("Human");
    }
    else {
        return std::string("Tower");
    }
}

void Cell::set_human(Human* human)
{
    if (this->is_empty() == "Empty") {
        object.first = human;
    }
}

void Cell::set_tower(Tower* tower)
{
    if(this->is_empty() == "Empty") {
        object.second = tower;
    }
}

Human* Cell::get_human()
{
    return object.first;
}

Tower* Cell::get_tower()
{
    return object.second;
}

void Cell::clear() {
    object.first = nullptr;
    object.second = nullptr;
}
