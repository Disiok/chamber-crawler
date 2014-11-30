#include "treasure.h"
#include "character.h"
#include "game.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constuctor & destructor
Treasure::Treasure(Tile *tile, int gold): Entity(tile), gold(gold) {}

Treasure::~Treasure() {};

// Entity methods
bool Treasure::isSteppable(Player *) {
	return true;
}

bool Treasure::steppedOnBy(Character *character) {
#ifdef DEBUG
	cout << "Treasure::steppedOnBy(Character *)" << endl;
#endif
	character->setGold(character->getGold() + gold);
	addGoldAction(gold);
	return true;
}

// Private Treasure method
void Treasure::addGoldAction(int gold) {
    ostringstream oss;
    oss << "Picked up " << gold << " gold. ";
    Game::getInstance()->addAction(oss.str());
}

char Treasure::getSymbol() {
	return SYMBOL_TREASURE;
}
