#include "enemy.h"
#include "game.h"
#include "floor.h"
#include "tile.h"
#include "entity.h"
#include "player.h"
#include "goblin.h"

#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

// Constructor & destructor
Enemy::Enemy(Tile *tile, int hp, int atk, int def):
	Character(tile, hp, atk, def, 0) {}

Enemy::~Enemy() {}

// Entity method
void Enemy::performAction() {
	invokeAbility();

    // Only attack if player is till alive, preventing 'double deaths'
	if (isPlayerNearby() && !Player::getInstance()->isDead()) {
		Player::getInstance()->attackedBy(this);
	} else {
		move();
	}
}

// Character method
void Enemy::addMissAction(Character *) {
	ostringstream oss;
	oss << getSymbol() << " missed on PC. ";
	Game::getInstance()->addAction(oss.str());
}

void Enemy::addAttackAction(Character *, int damage) {
	ostringstream oss;
	oss << getSymbol() << " deals " << damage <<  " damage to PC. ";
	Game::getInstance()->addAction(oss.str());
}

bool Enemy::attackedBy(Goblin *goblin) {
    goblin->attack(this);
    if (isDead()) {
        killedBy(goblin);
    }
    return true;
}

void Enemy::killedBy(Character *other) {
	int gold = other->calculateGoldFrom(this);
	other->setGold(other->getGold() + gold);
	getCell()->destroyEntity();

	addKilledAction(gold);
}

// Enemy methods
void Enemy::killedBy(Goblin *goblin) {
    int gold = goblin->calculateGoldFrom(this);
    goblin->setGold(goblin->getGold() + gold);
    getCell()->destroyEntity();

    addKilledAction(gold);
}

void Enemy::addKilledAction(int gold) {
	ostringstream oss;
	oss << "PC killed " << getSymbol() << " for " << gold << " gold. ";
	Game::getInstance()->addAction(oss.str());
}

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
        Character::move(cell);
    }
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

