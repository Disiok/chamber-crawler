#include "character.h"
#include "entity.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

Character::Character(Tile *tile, char symbol, int hp, int atk, int def, int gold, const char typeIdentifier, const string typeName):
	Entity(tile, symbol),
	typeIdentifier(typeIdentifier),
	typeName(typeName),
	hp(hp),
	atk(atk),
	def(def),
	gold(gold) {}

Character::~Character() {}

void Character::move() {
	// TODO: Finish move logic
}

void Character::killedBy(Character *other) {
	// TODO: Finish dying logic
}

void Character::attack(Character *other) {
#ifdef DEBUG
	cout << "Character::attack" << endl;
#endif
	int damage = ceil(100/ (float)(100 + other->getDef()) * getAtk());
	other->setHP(other->getHP() - damage);
}

bool Character::attackedBy(Character *other) {
	other->attack(this);
	if (isDead()) {
		killedBy(other);
	}
	return true;
}


int Character::getHP() {
	return hp;
}

int Character::getAtk() {
	return atk;
}

int Character::getDef() {
	return def;
}

int Character::getGold() {
	return gold;
}

void Character::setHP(int hp) {
	this->hp = hp;
}

void Character::setAtk(int atk) {
	this->atk = atk;
}

void Character::setDef(int def) {
	this->def = def;
}

void Character::setGold(int gold) {
	this->gold = gold;
}

bool Character::isDead() {
	return hp <= 0;
}
