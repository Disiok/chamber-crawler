#include "troll.h"
#include <iostream>
#include <string>
#include "tile.h"
using namespace std;

const string Troll::TYPE_NAME = "Troll";

Troll::Troll(Tile *tile): Player(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Troll::Troll" << endl;
#endif
};

void Troll::invokeAbility() {
	setHP(getHP() + 5);
}
