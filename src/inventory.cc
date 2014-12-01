#include "inventory.h"
#include "game.h"
#include "character.h"
#include "cell.h"
#include "drow.h"
#include <string>
#include <sstream>
using namespace std;

Inventory::Inventory(Tile *tile): Entity(tile) {}

Inventory::~Inventory() {};

bool Inventory::pickedUpBy(Character *character) {
	cell->clearEntity();
	
	Player *player = dynamic_cast<Player *>(character);
	player->addInventory(this);
	
	addPickupAction();
	return true;
}

bool Inventory::pickedUpBy(Drow *drow) {
	return Inventory::pickedUpBy(dynamic_cast<Character *>(drow));

}

void Inventory::addPickupAction() {
	ostringstream oss;
	oss << "Picked up a " << getName() << ". ";
	Game::getInstance()->addAction(oss.str());

}
