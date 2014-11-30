#include "vampire.h"
#include "dwarf.h"
#include <iostream>
#include <string>
using namespace std;

const string Vampire::NAME_VAMPIRE = "Vampire";

Vampire::Vampire(Tile *tile): Player(tile, HP, ATK, DEF) {
#ifdef DEBUG
	cout << "Vampire::Vampire" << endl;
#endif
}

void Vampire::attack(Character *other) {
	Character::attack(other);

	// Life steal
	setHP(getHP() + 5);
}

void Vampire::attack(Dwarf *dwarf) {
	Character::attack(dwarf);

	// Reverse life steal
	setHP(getHP() - 5);

}

void Vampire::setHP(int hp) {
	this->hp = max(0, hp);
}

string Vampire::getName() {
	return NAME_VAMPIRE;
}
