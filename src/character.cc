#include "character.h"
#include "cell.h"
#include "tile.h"
#include "entity.h"
#include "drow.h"
#include "merchant.h"
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

// Constructor & destructor
Character::Character(Tile *tile,int hp, int atk, int def, int gold) :
	Entity(tile),
	maxHP(hp),
	hp(hp),
	atk(atk),
	def(def),
	gold(gold) {}

Character::~Character() {}

// Combat methods
void Character::attack(Character *other) {
#ifdef DEBUG
	cout << "Character::attack" << endl;
#endif
	int damage = calculateDamageOn(other);
	other->setHP(other->getHP() - damage);
	addAttackAction(other, damage);
}

void Character::attack(Dwarf *dwarf) {
	Character::attack(dynamic_cast<Character *>(dwarf));
}

void Character::attack(Drow *drow) {
	Character::attack(dynamic_cast<Character *>(drow));
}

void Character::attack(Goblin *goblin) {
	int damage = calculateDamageOn(goblin);
	goblin->setHP(goblin->getHP() - damage);
	addAttackAction(goblin, damage);
}

bool Character::attackedBy(Character *other) {
	other->attack(this);
	if (isDead()) {
		killedBy(other);
	}
	return true;
}

bool Character::attackedBy(Goblin *) {
	return true;
}

bool Character::isDead() {
	return hp == 0;
}

// Damage calculation
int Character::calculateDamageOn(Character *other) {
	return ceil(100/ (float)(100 + other->getDef()) * getAtk());
}

int Character::calculateDamageOn(Goblin *goblin) {
	return calculateDamageOn(dynamic_cast<Character *>(goblin));
}


// Gold calculation
int Character::calculateGoldFrom(Character *) {
	return (rand() % 2) ? 1 : 2;
}

int Character::calculateGoldFrom(Human *) {
	return 4;
}

int Character::calculateGoldFrom(Merchant *) {
	return 0;
}

// Other methods
bool Character::move(Cell *cell) {
	getCell()->clearEntity();
	setCell(cell);
	cell->steppedOnBy(this);
	cell->setEntity(this);
	return true;
}

void Character::invokeAbility() {}

// Accessors
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

// Mutators
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
