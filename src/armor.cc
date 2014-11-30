#include "armor.h"
#include <cstdlib>

Armor::Armor(Tile *tile): Equipment(tile, SYMBOL_ARMOR) {
	def = rand() % 20;
}

int Armor::getDef() {
	return def;
}
