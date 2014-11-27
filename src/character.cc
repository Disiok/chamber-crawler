#include "character.h"
#include "cell.h"
#include "tile.h"
#include "entity.h"
#include <cmath>
#include "game.h"
#include <sstream>
#include <iostream>
#include "game.h"
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

void Character::move(Cell *cell) {
	getCell()->clearEntity();
	setCell(cell);
	cell->steppedOnBy(this);
	cell->setEntity(this);
}

void Character::killedBy(Character *other) {
	// TODO: Finish dying logic
}

void Character::attack(Character *other) {
#ifdef DEBUG
	cout << "Character::attack" << endl;
#endif
	int damage = calculateDamage(other);
	addAttackAction(other, damage);
	other->setHP(other->getHP() - damage);
}

int Character::calculateDamage(Character *other) {
	return ceil(100/ (float)(100 + other->getDef()) * getAtk());

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

void Character::addMissAction(Character *other) {
	ostringstream oss;
	oss << other->getTypeId() << " missed. ";
	Game::getInstance()->addAction(oss.str());
}
