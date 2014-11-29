#include "restorehealth.h"
using namespace std;

const string RestoreHealth::typeName = "Restore Health";
bool RestoreHealth::revealed = false;

RestoreHealth::RestoreHealth(Tile *tile): Potion(tile, typeName) {}

bool RestoreHealth::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setHP(character->getHP() + 10);
        Potion::pickedUpBy(character);
    }
}