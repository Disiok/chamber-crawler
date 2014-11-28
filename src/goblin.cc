#include "player.h"
#include "goblin.h"
#include "character.h"
#include <string>
#include <iostream>
using namespace std;

const string Goblin::TYPE_NAME = "Goblin";

Goblin::Goblin(Tile *tile): Player(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {
#ifdef DEBUG
	cout << "Goblin::Goblin" << endl;
#endif
}

int Goblin::calculateGoldFrom(Character *other) {
	return Character::calculateGoldFrom(other) + 5;
}
