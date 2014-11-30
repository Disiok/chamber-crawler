#include "merchantTreasure.h"
#include <string>
using namespace std;

const string MerchantTreasure::NAME_MERCHANT_TREASURE = "Merchant Treasure";

MerchantTreasure::MerchantTreasure(Tile *tile): Treasure(tile, GOLD_MERCHANT) {}

string MerchantTreasure::getName() {
	return NAME_MERCHANT_TREASURE;
}
