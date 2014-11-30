#include "inventory.h"
#include <string>
#include <sstream>
#include "game.h"
#include "character.h"
#include "drow.h"
using namespace std;

Inventory::Inventory(Tile *tile, char symbol): Entity(tile, symbol) {}

Inventory::~Inventory() {};

string Inventory::getName() {
	return "Inventory Stub";
}

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
	// TODO: Add name of inventory
	ostringstream oss;
	oss << "Picked up an inventory. ";
	Game::getInstance()->addAction(oss.str());

}
