#include "enemy.h"
#include "tile.h"
#include <string>
#include "player.h"
#include "entity.h"
#include <cstdlib>
using namespace std;

Enemy::Enemy(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const string typeName):
	Character(tile, typeIdentifier, hp, atk, def, 0, typeIdentifier, typeName) {}

Enemy::~Enemy() {}

void Enemy::move() {

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
