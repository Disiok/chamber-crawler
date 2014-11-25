#include "halfling.h"
#include <string>
using namespace std;

const string Halfling::TYPE_NAME = "Halfling";

Halfling::Halfling(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}
