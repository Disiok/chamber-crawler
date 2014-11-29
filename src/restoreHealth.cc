#include "restorehealth.h"
using namespace std;

const string RestoreHealth::typeIdentifier = "Restore Health";

RestoreHealth::RestoreHealth(Tile *tile): Potion(tile, typeIdentifier) {}