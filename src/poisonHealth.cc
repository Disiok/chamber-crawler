#include "poisonHealth.h"
using namespace std;

const string PoisonHealth::typeIdentifier = "Poison Health";

PoisonHealth::PoisonHealth(Tile *tile): Potion(tile, typeIdentifier) {}