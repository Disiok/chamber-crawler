#include "sword.h"
#include <cstdlib>

Sword::Sword(Tile *tile): Equipment(tile, SYMBOL_SWORD) {
	atk = rand() % 20;
}

int Sword::getAtk() {
	return atk;
}
