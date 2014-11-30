#include "inventory.h"
#include <string>
using namespace std;

Inventory::Inventory(Tile *tile, char symbol): Entity(tile, symbol) {}

string Inventory::getName() {
	return "Inventory Stub";
}
