#include "enemy.h"
#include <string>
using namespace std;

Enemy::Enemy(Tile *tile, int hp, int atk, int def, const char typeIdentifier, const string typeName): 
	Character(tile, typeIdentifier, hp, atk, def, 0, typeIdentifier, typeName) {}

Enemy::~Enemy() {}

void Enemy::move() {

}

void Enemy::performAction() {

}

void Enemy::killedBy(Character *other) {

}

bool Enemy::attackedBy(Character *other) {
	Character::attackedBy(other);
	other->attackedBy(this);
	return true;
}
