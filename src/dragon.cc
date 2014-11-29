#include "dragon.h"
#include "cell.h"
#include "dragonTreasure.h"
#include "player.h"
#include <cstdlib>
using namespace std;

const string Dragon::TYPE_NAME = "Dragon";

Dragon::Dragon(Tile *tile, DragonTreasure *treasure): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME), treasure(treasure) {}

// Dragons don't move
void Dragon::move() {}

/* *
 * Dragon::isPlayerNearby
 *  Checks around the dragon's treasure to see if there's a player.
 */
bool Dragon::isPlayerNearby() {
    if (!Enemy::isPlayerNearby()) {
        Cell *current = treasure->getCell();
        Cell *other = Player::getInstance()->getCell();
        int i1 = current->getI();
        int j1 = current->getJ();
        int i2 = other->getI();
        int j2 = other->getJ();
        return abs(i1 - i2) <= 1 && abs(j1 - j2) <= 1;
    }
    return true;
}

void Dragon::killedBy(Character *other) {
    // Treasure is accessible after dragon's death
    treasure->unlock();
    Enemy::killedBy(other);
}