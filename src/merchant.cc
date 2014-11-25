#include "merchant.h"
#include <string>
using namespace std;

const string Merchant::TYPE_NAME = "Merchant";

Merchant::Merchant(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}
