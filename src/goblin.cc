#include "player.h"
#include "goblin.h"
#include "cell.h"
#include "character.h"
#include "merchant.h"
#include <string>
#include <iostream>
using namespace std;

const string Goblin::NAME_GOBLIN = "Goblin";

Goblin::Goblin(Tile *tile): Player(tile, HP, ATK, DEF) {
#ifdef DEBUG
	cout << "Goblin::Goblin" << endl;
#endif
}

int Goblin::calculateGoldFrom(Character *other) {
	return Character::calculateGoldFrom(other) + 5;
}

int Goblin::calculateGoldFrom(Merchant *merchant) {
    return Character::calculateGoldFrom(merchant) + 5;
}

int Goblin::calculateGoldFrom(Human *human) {
    return Character::calculateGoldFrom(human) + 5;
}

bool Goblin::attackedBy(Character *other) {
    other->attack(this);
    if (isDead()) {
        killedBy(other);
    }
    return true;
}

bool Goblin::engage(Cell *cell) {
    return cell->attackedBy(this);
}

string Goblin::getName() {
	return NAME_GOBLIN;
}
