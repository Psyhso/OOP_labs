#include "Enemy.h"
#include "GameArea.h"


bool Enemy::attack(Coords enemy_coords, GameArea& gamearea)
{
    if (!gamearea.player_or_enemy(enemy_coords)) {
        throw FriendInCell();
    }
    bool win = gamearea.attack(this, enemy_coords, damage_calculation());
    if (win) {
        throw PlayerDyeException();
    }
    return win;
}

double Enemy::get_coast_exp()
{
    return coast_exp;
}
