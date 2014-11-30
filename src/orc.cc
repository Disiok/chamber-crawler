#include "orc.h"
#include "character.h"
#include "goblin.h"
#include <cmath>
#include <string>
using namespace std;

const string Orc::NAME_ORC = "Orc";

Orc::Orc(Tile *tile): Enemy(tile, HP, ATK, DEF) {}

int Orc::calculateDamageOn(Goblin *goblin) {
	return ceil(1.5 * Character::calculateDamageOn(goblin));
}

void Orc::attack(Goblin *goblin) {
    Character::attack(goblin);
}

char Orc::getSymbol() {
	return SYMBOL_ORC;
}

string Orc::getName() {
	return NAME_ORC;
}
