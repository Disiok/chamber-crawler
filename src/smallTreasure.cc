#include "smallTreasure.h"
#include <string>
using namespace std;

const string SmallTreasure::NAME_SMALL_TREASURE = "Small Treasure";

SmallTreasure::SmallTreasure(Tile *tile): Treasure(tile, GOLD_SMALL) {}

string SmallTreasure::getName() {
	return NAME_SMALL_TREASURE;
}
