#include "sword.h"
#include "player.h"
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

const string Sword::NAME_SWORD = "Sword";
Sword::Sword(Tile *tile): Equipment(tile) {
	int rating = rand() % 10;
	if (rating >= 90) {
		atk = 50 + rand() % 15;
	} else if (rating >= 6) {
		atk = 20 + rand() % 10;
	} else {
		atk = 10 + rand() % 5;
	}
}

int Sword::getAtk() {
	return atk;
}

void Sword::usedBy(Player *player) {
	player->equip(this);
}

string Sword::getName() {
	ostringstream oss;
	oss << NAME_SWORD << " +" << atk; 
	return oss.str();
}

char Sword::getSymbol() {
	return SYMBOL_SWORD;
}
