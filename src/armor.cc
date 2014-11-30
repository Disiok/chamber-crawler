#include "armor.h"
#include "player.h"
#include <cstdlib>

Armor::Armor(Tile *tile): Equipment(tile, SYMBOL_ARMOR) {
	int rating = rand() % 100;
	if (rating == 100) {
		def = 50;
	} else if (rating >= 75) {
		def = 20;
	} else {
		def = 10;
	}
}

int Armor::getDef() {
	return def;
}

void Armor::usedBy(Player *player) {
	player->equip(this);
}

