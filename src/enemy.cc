#include "enemy.h"
#include "tile.h"
#include <string>
#include "player.h"
#include "entity.h"
#include "floor.h"
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

Enemy::Enemy(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const string typeName):
	Character(tile, typeIdentifier, hp, atk, def, 0, typeIdentifier, typeName) {}

Enemy::~Enemy() {}

/* *
 * move
 *  Chooses a random, adjacent, empty, and steppable cell for the enemy to move to.
 */
void Enemy::move() {
    vector<Cell *> steppableCells;
    int i = getCell()->getI();
    int j = getCell()->getJ();
    // Check each side and add to vector if cell is steppable
    for (int a = -1 ; a <= 1 ; a++) {
        for (int b = -1 ; b <= 1 ; b++) {
            if (getCell()->getFloor()->getCell(i+a, j+b)->isSteppable(this)) {
                steppableCells.push_back(getCell()->getFloor()->getCell(i+a, j+b));
            }
        }
    }

    if (steppableCells.size() == 0) {
        return;
    } else {
        // Moving enemy
        int roll = rand() % steppableCells.size();
        Cell *cell = steppableCells.at(roll);
        cell->setEntity(this);
        Character::move(cell);
    }
}

void Enemy::performAction() {
	if (isPlayerNearby()) {
		Player::getInstance()->attackedBy(this);
	} else {
		move();
	}
}

void Enemy::killedBy(Character *other) {

}

bool Enemy::attackedBy(Character *other) {
	Character::attackedBy(other);
	other->attackedBy(this);
	return true;
}

bool Enemy::isPlayerNearby() {
	Cell *current = getCell();
	Cell *other = Player::getInstance()->getCell();
	int i1 = current->getI();
	int j1 = current->getJ();
	int i2 = other->getI();
	int j2 = other->getJ();
	return abs(i1 - i2) <= 1 && abs(j1 - j2) <= 1;
}

bool Enemy::isSteppable(Player *player) {
    return false;
}
