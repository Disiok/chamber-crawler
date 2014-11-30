#include "restorehealth.h"
#include "drow.h"
#include <cmath>
using namespace std;

const string RestoreHealth::typeName = "Restore Health";
const int RestoreHealth::EFFECT = 10;
bool RestoreHealth::revealed = false;

void RestoreHealth::resetRevealed() {
    revealed = false;
}

RestoreHealth::RestoreHealth(Tile *tile): Potion(tile, typeName) {}

bool RestoreHealth::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setHP(character->getHP() + ceil(EFFECT * multiplier));
        Potion::pickedUpBy(character);
    }
}

bool RestoreHealth::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    RestoreHealth::pickedUpBy(dynamic_cast<Character *>(drow));
}