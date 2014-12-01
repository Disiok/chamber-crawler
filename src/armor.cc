#include "armor.h"
#include "player.h"
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

const string Armor::NAME_ARMOR = "Armor";

Armor::Armor(Tile *tile): Equipment(tile) {
	int rating = rand() % 10;
	if (rating >= 9) {
		def = 50 + rand() % 15;
	} else if (rating >= 6) {
		def = 20 + rand() % 10;
	} else {
		def = 10 + rand() % 5;
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
	ostringstream oss;
	oss << NAME_ARMOR << " +" << def;
	return oss.str();
}
