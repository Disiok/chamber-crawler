#include "troll.h"
#include <iostream>
#include <string>
#include "tile.h"
using namespace std;

const string Troll::NAME_TROLL = "Troll";

Troll::Troll(Tile *tile): Player(tile, HP, ATK, DEF) {
#ifdef DEBUG
	cout << "Troll::Troll" << endl;
#endif
};

void Troll::invokeAbility() {
	setHP(getHP() + 5);
}

string Troll::getName() {
	return NAME_TROLL;
}
