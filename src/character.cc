#include "character.h"
#include "cell.h"
#include "tile.h"
#include "entity.h"
#include "drow.h"
#include "dwarf.h"
#include "human.h"
#include <cmath>
#include "game.h"
#include "goblin.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Character::Character(Tile *tile, char symbol, int hp, int atk, int def, int gold, const char typeIdentifier, const string typeName):
	Entity(tile, symbol),
	typeIdentifier(typeIdentifier),
	typeName(typeName),
	maxHP(hp),
	hp(hp),
	atk(atk),
	def(def),
	gold(gold) {}

Character::~Character() {}

void Character::move(Cell *cell) {
	getCell()->clearEntity();
	setCell(cell);
	cell->steppedOnBy(this);
	cell->setEntity(this);
}

void Character::attack(Character *other) {
#ifdef DEBUG
	cout << "Character::attack" << endl;
#endif
	int damage = calculateDamageOn(other);
	other->setHP(other->getHP() - damage);
	addAttackAction(other, damage);
}

void Character::attack(Dwarf *dwarf) {
	attack(dynamic_cast<Character *>(dwarf));
}

void Character::attack(Drow *drow) {
	attack(dynamic_cast<Character *>(drow));
}

int Character::calculateDamageOn(Character *other) {
	return ceil(100/ (float)(100 + other->getDef()) * getAtk());
}

int Character::calculateDamageOn(Goblin *goblin) {
	return calculateDamageOn((Character *) goblin);
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

char Character::getTypeId() {
	return typeIdentifier;
}

string Character::getTypeName() {
	return typeName;
}

void Character::setHP(int hp) {
	this->hp = min(maxHP, max(0, hp));
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
	return hp == 0;
}

void Character::invokeAbility() {}

int Character::calculateGoldFrom(Character *other) {
	return (rand() % 2) ? 1 : 2;
}

int Character::calculateGoldFrom(Human *human) {
	return 4;
}
