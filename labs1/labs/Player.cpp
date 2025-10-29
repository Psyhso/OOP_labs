#include "Player.h"
#include "GameArea.h"


bool Player::attack(Coords enemy_coords, GameArea& gamearea)
{ 
	bool win = gamearea.attack(this, enemy_coords, damage_calculation());
	if (win) {
		if (experience > experience_for_new_level) {
			up_level();
		}
	}
	return win;
}

void Player::up_level()
{
	double rest_exp = experience - experience_for_new_level;
	level++;
	experience = rest_exp;
	health += (health / 100) * 5;
	damage += (damage / 100) * 5;
}

void Player::up_exp(double input_exp)
{
	experience += input_exp;
}

double Player::get_exp()
{
	return experience;
}

void Player::change_range()
{
	if (melee) {
		melee = false;
		damage -= (damage / 100) * 20;
		return;
	}
	melee = true;
	damage += (damage / 100) * 20;
}

