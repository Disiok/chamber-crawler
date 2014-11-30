#include "halfling.h"
#include <string>
#include <cstdlib>
using namespace std;

const string Halfling::NAME_HALFLING = "Halfling";

Halfling::Halfling(Tile *tile): Enemy(tile, HP, ATK, DEF) {}

bool Halfling::attackedBy(Character *other) {
	if (rand() % 2) {
		Character::attackedBy(other);
	} else {
		other->addMissAction(this);
	}
	return true;
}

char Halfling::getSymbol() {
	return SYMBOL_HALFLING;
}

string Halfling::getName() {
	return NAME_HALFLING;
}
