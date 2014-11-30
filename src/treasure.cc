#include "treasure.h"
#include "character.h"
#include <iostream>
#include <sstream>
#include "game.h"
using namespace std;

Treasure::Treasure(Tile *tile, int gold): Entity(tile, SYMBOL_TREASURE), gold(gold) {}

Treasure::~Treasure() {};

bool Treasure::isSteppable(Player *player) {
	return true;
}

bool Treasure::isSteppable(Enemy *enemy) {
	return false;
}

bool Treasure::steppedOnBy(Character *character) {
#ifdef DEBUG
	cout << "Treasure::steppedOnBy(Character *)" << endl;
#endif
	character->setGold(character->getGold() + gold);
	addGoldAction(gold);
	return true;
}

void Treasure::addGoldAction(int gold) {
    ostringstream oss;
    oss << "Picked up " << gold << " gold. ";
    Game::getInstance()->addAction(oss.str());
}
