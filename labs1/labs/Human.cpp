#include "Human.h"

Coords Human::get_coords()
{
	return coords;
}

Coords Human::set_coords(int x, int y)
{
	coords.x = x;
	coords.y = y;
}

bool Human::moving(std::string direction, GameArea& gamearea)
{
	Coords new_coords = coords;
	if (direction == "top") {
		new_coords.y++;
		std::string obj_in_new_cell = gamearea.can_move_to(new_coords);
		if (obj_in_new_cell == "Edge" || obj_in_new_cell == "Tower") {
			return false;
		}
		else if (obj_in_new_cell == "Empty") {
			gamearea.move_human(coords, new_coords, this);
		}
		else if (obj_in_new_cell == "Human") {
			
		}
	}
	else if (direction == "down") {
		new_coords.y--;
		std::string obj_in_new_cell = gamearea.can_move_to(new_coords);
	}
	else if (direction == "right") {
		new_coords.x++;
		std::string obj_in_new_cell = gamearea.can_move_to(new_coords);
	}
	else if (direction == "left") {
		new_coords.x--;
		std::string obj_in_new_cell = gamearea.can_move_to(new_coords);
	}
}