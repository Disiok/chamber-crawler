#include "treasure.h"
#include "character.h"

Treasure::Treasure(Tile *tile, int gold): Entity(tile, SYMBOL_TREASURE), gold(gold) {}

Treasure::~Treasure() {};

bool Treasure::isSteppable(Player *player) {
	return true;
}

bool Treasure::isSteppable(Enemy *enemy) {
	return false;
}

bool Treasure::steppedOnBy(Character *character) {
	character->setGold(character->getGold() + gold);
	return true;
}
