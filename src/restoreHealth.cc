#include "restorehealth.h"
using namespace std;

const string RestoreHealth::typeIdentifier = "Restore Health";

RestoreHealth::RestoreHealth(Tile *tile): Potion(tile, typeIdentifier) {}

bool RestoreHealth::pickedUpBy(Character *character) {
    character->setHP(character->getHP() + 10);
    Potion::pickedUpBy(character);
}