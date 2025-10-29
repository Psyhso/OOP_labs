#include "Cell.h"
#include "GameArea.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyBuilding.h"
#include "Building.h"

#include <iostream>

int main() {
	//Инициализация поля
	//GameArea gamearea(5, 5);
	//std::cout << "GameArea success!\n";
	////gamearea.print_area();
	////Инициализация игрока и врагов
	//Coords player_coords(1, 1);
	//Player player(100, 50, player_coords);
	////std::cout << player.get_coords().x << player.get_coords().y << '\n';

	//Enemy enemy1(100, 101, Coords(2, 2));
	//Enemy enemy2(20, 2, Coords(4,4));

	//std::vector<Enemy*> vct;
	//vct.push_back(&enemy1);
	//vct.push_back(&enemy2);

	////Поставим здания
	//EnemyBuilding building1(15, Coords(0,2), 3);

	//std::vector<Building*> vct_b;
	//vct_b.push_back(&building1);

	//////Заполнение игрового поля
	//gamearea.fill_area(&player, vct, vct_b);
	//
	//////Посмотрим поле
	////gamearea.print_area();
	//std::cout << '\n';

	//////Подвигаем игрока и врага
	//player.moving(std::string("down"), gamearea);
	//enemy1.moving(std::string("right"), gamearea);

	////enemy1.moving(std::string("down"), gamearea);
	////enemy1.moving(std::string("down"), gamearea);
	////enemy1.moving(std::string("down"), gamearea);
	////enemy1.moving(std::string("right"), gamearea);
	////enemy1.moving(std::string("right"), gamearea);
	////gamearea.print_area();
	////////Атакуем enemy1
	//player.moving(std::string("right"), gamearea);
	//player.moving(std::string("right"), gamearea);
	////std::cout <<'\n' << player.get_exp() << '\n';


	////Здание спавнит моба
	//building1.plus_step(gamearea);
	//building1.plus_step(gamearea);
	//building1.plus_step(gamearea);
	//gamearea.print_area();
	//Enemy1 атакует игрока и убивает его
	//enemy1.moving(std::string("left"), gamearea);

	////Посмотрим поле
	//gamearea.print_area();

	GameArea gamearea(3, 3);
	std::cout << "GameArea success!\n";
	
	//Инициализация игрока и врагов
	Coords player_coords(2, 0);
	Player player(100, 10, player_coords);
	//std::cout << player.get_coords().x << player.get_coords().y << '\n';

	std::vector<Enemy*> vct;
	std::vector<Building*> vct_b;

	//Заполнение игрового поля
	gamearea.fill_area(&player, vct, vct_b);
	gamearea.print_area();

	//////Пытаемся пройти через замедляющую клетку
	player.moving("left", gamearea);
	player.moving("down", gamearea);
	std::cout << player.stunned_or_not() << '\n';
	////std::cout << player.get_coords().x << ' ' << player.get_coords().y << '\n';
	player.moving("left", gamearea);
	player.moving("left", gamearea);
	////std::cout << player.get_coords().x << ' ' << player.get_coords().y << '\n';
	player.moving("down", gamearea);
	player.moving("right", gamearea);
	//std::cout << '\n';
	gamearea.print_area();
	return 0;
}
