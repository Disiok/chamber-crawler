#include "merchant.h"
#include "merchantTreasure.h"
#include "cell.h"
#include "game.h"
#include <sstream>
#include <string>
using namespace std;

bool Merchant::isHostile = false;
const string Merchant::TYPE_NAME = "Merchant";

Merchant::Merchant(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}

void Merchant::resetHostile() {
	isHostile = false;
}

bool Merchant::attackedBy(Character *other) {
	isHostile = true;
	return Character::attackedBy(other);
}

bool Merchant::isPlayerNearby() {
	if (isHostile) {
		return Enemy::isPlayerNearby();
		Enemy::performAction();
	} else {
		return false;
	}
}

void Merchant::killedBy(Character *other) {
	addKilledAction();

	Cell *cell = getCell();
	cell->destroyEntity();
	cell->setEntity(new MerchantTreasure((Tile *)cell));
}

void Merchant::addKilledAction() {
	ostringstream oss;
	oss << "PC killed " << getTypeId() << ". A pile of gold is dropped. ";
	Game::getInstance()->addAction(oss.str());
}

