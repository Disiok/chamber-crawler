#include "normalTreasure.h"
#include <string>
using namespace std;

const string NormalTreasure::NAME_NORMAL_TREASURE = "Normal Treasure";

NormalTreasure::NormalTreasure(Tile *tile): Treasure(tile, GOLD_NORMAL) {}

string NormalTreasure::getName() {
	return NAME_NORMAL_TREASURE;
}
