#include "restoreHealth.h"
#include "drow.h"
#include <cmath>
using namespace std;

const string RestoreHealth::NAME_RH = "Restore Health";
const int RestoreHealth::EFFECT = 10;
bool RestoreHealth::revealed = false;

void RestoreHealth::resetRevealed() {
    revealed = false;
}

RestoreHealth::RestoreHealth(Tile *tile): Potion(tile), multiplier(1) {}

bool RestoreHealth::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setHP(character->getHP() + ceil(EFFECT * multiplier));
        return Potion::pickedUpBy(character);
    }
    return false;
}

bool RestoreHealth::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    return RestoreHealth::pickedUpBy(dynamic_cast<Character *>(drow));
}

string RestoreHealth::getName() {
	return NAME_RH;
}
