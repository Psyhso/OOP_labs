#include "GameArea.h"

void GameArea::set_human_in_cell(Coords object_coords, Human* human)
{
	area[object_coords.y][object_coords.x].set_human(human);
}

void GameArea::set_tower_in_cell(Coords object_coords, Tower* tower)
{
	area[object_coords.y][object_coords.x].set_tower(tower);
}

void GameArea::fill_area(Player* player, std::vector<Enemy*> enemyes)
{
	Coords player_coords = player->get_coords();
	set_human_in_cell(player_coords, player);
	for (auto enemy : enemyes) {
		Coords enemy_coords = enemy->get_coords();
		set_human_in_cell(enemy_coords, enemy);
	}
}

void GameArea::move_human(Coords from, Coords to, Human* human)
{
	area[from.x][from.y].clear();
	area[to.x][to.y].set_human(human);
}

std::string GameArea::can_move_to(Coords move_coords)
{
	if (move_coords.x > width - 1 && move_coords.y > height - 1) {
		return std::string("Edge");
	}
	else {
		return area[move_coords.y][move_coords.x].is_empty();
	}
}
