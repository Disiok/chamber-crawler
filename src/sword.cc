#include "sword.h"
#include "player.h"
#include <cstdlib>

Sword::Sword(Tile *tile): Equipment(tile, SYMBOL_SWORD) {
	int rating = rand() % 100;
	if (rating == 100) {
		atk = 50;
	} else if (rating >= 75) {
		atk = 20;
	} else {
		atk = 10;
	}
}

int Sword::getAtk() {
	return atk;
}

void Sword::usedBy(Player *player) {
	player->equip(this);
}
