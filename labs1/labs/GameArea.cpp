#include "GameArea.h"
#include "Player.h"
#include "Enemy.h"
#include "Building.h"

void GameArea::set_human_in_cell(Coords object_coords, Human* human)
{
	area[object_coords.y][object_coords.x].set_human(human);
}

void GameArea::set_building_in_cell(Coords object_coords, Building* building)
{
	area[object_coords.y][object_coords.x].set_building(building);
}

void GameArea::fill_area(Player* player, std::vector<Enemy*> enemyes, std::vector<Building*> buildings)
{
	double count_another_cell = (((double)height * (double)width) / 100) * 10 + 1;
	for (int i = 0; i < count_another_cell; i++) {
		int x_block = rand() % width;
		int y_block = rand() % height;
		area[x_block][y_block].set_type(CellType::BLOCKED);

		int x_slow = rand() % width;
		int y_slow = rand() % height;
		area[x_slow][y_slow].set_type(CellType::SLOW);
	}

	Coords player_coords = player->get_coords();
	set_human_in_cell(player_coords, player);
	for (auto enemy : enemyes) {
		Coords enemy_coords = enemy->get_coords();
		set_human_in_cell(enemy_coords, enemy);
	}

	for (auto building : buildings) {
		Coords building_coords = building->get_coords();
		set_building_in_cell(building_coords, building);
	}
}

void GameArea::print_area()
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::string obj = area[y][x].is_empty();
			if (obj == "Empty") {
				std::cout << area[y][x].get_type_string() << ' ';
			}
			else {
				std::cout << obj << ' ';
			}
		}
		std::cout << '\n';
	}
}

void GameArea::move_human(Coords from, Coords to, Human* human)
{

	if (human->stunned_or_not()) {
		human->set_stunned(false);
		std::cout << "You are stanned.\n";
		return;
	}

	area[from.y][from.x].clear();
	area[to.y][to.x].set_human(human);

	if (area[to.y][to.x].get_type() == CellType::SLOW) {
		human->set_stunned(true);
	}
}

bool GameArea::player_or_enemy(Coords coords)
{
	return area[coords.y][coords.x].player_or_enemy();
}

bool GameArea::attack(Human* human, Coords enemy_coords, double input_damage)
{
	Human* enemy = area[enemy_coords.y][enemy_coords.x].get_human();
	enemy->take_damage(input_damage);

	double enemy_health = enemy->get_health();
	if (enemy_health <= 0) {
		Coords old_coords = human->get_coords();
		if (area[old_coords.y][old_coords.x].player_or_enemy()) {
			Player* plaeyr_ptr = static_cast<Player*>(human);
			plaeyr_ptr->up_exp(get_coast_exp_enemy(enemy_coords));
			//std::cout << get_coast_exp_enemy(enemy_coords) << " up expirence";
		}
		move_human(old_coords, enemy_coords, human);
		return true;
	}
	return false;
}

std::string GameArea::can_move_to(Coords move_coords)
{
	if (!is_valid_coords(move_coords) || !is_valid_coords(move_coords)) {
		return std::string("Edge");
	}
	else {
		return area[move_coords.y][move_coords.x].is_empty();
	}
}

CellType GameArea::get_cell_type(Coords coords)
{
	return area[coords.y][coords.x].get_type();
}

double GameArea::get_coast_exp_enemy(Coords coords)
{
	Human* enemy = area[coords.y][coords.x].get_human();
	Enemy* enemy_ptr = static_cast<Enemy*>(enemy);
	return enemy_ptr->get_coast_exp();
}

bool GameArea::is_valid_coords(Coords& coord) {
	return coord.x >= 0 && coord.x < width && coord.y >= 0 && coord.y < height;
}