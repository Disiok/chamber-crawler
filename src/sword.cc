#include "sword.h"
#include "player.h"
#include <cstdlib>
#include <string>
using namespace std;

const string Sword::NAME_SWORD = "Sword";
Sword::Sword(Tile *tile): Equipment(tile) {
	int rating = rand() % 10;
	if (rating >= 90) {
		atk = 50;
	} else if (rating >= 6) {
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

string Sword::getName() {
	return NAME_SWORD;
}

char Sword::getSymbol() {
	return SYMBOL_SWORD;
}
