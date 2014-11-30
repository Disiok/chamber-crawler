#include "armor.h"
#include "player.h"
#include <cstdlib>
#include <string>
using namespace std;

const string Armor::NAME_ARMOR = "Armor";

Armor::Armor(Tile *tile): Equipment(tile) {
	int rating = rand() % 10;
	if (rating >= 9) {
		def = 50;
	} else if (rating >= 6) {
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

char Armor::getSymbol() {
	return SYMBOL_ARMOR;
}
string Armor::getName() {
	return NAME_ARMOR;
}
