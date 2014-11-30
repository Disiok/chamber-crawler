#include "dwarf.h"
#include <string>
using namespace std;

const string Dwarf::NAME_DWARF = "Dwarf";

Dwarf::Dwarf(Tile *tile): Enemy(tile, HP, ATK, DEF) {}

bool Dwarf::attackedBy(Character *other) {
    other->attack(this);
    if (isDead()) {
        killedBy(other);
    }
    return true;
}

char Dwarf::getSymbol() {
	return SYMBOL_DWARF;
}

string Dwarf::getName() {
	return NAME_DWARF;
}
