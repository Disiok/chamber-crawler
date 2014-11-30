#include "poisonHealth.h"
#include "drow.h"
#include <cmath>
using namespace std;

const string PoisonHealth::typeName = "Poison Health";
const int PoisonHealth::EFFECT = -10;
bool PoisonHealth::revealed = false;

void PoisonHealth::resetRevealed() {
    revealed = false;
}

PoisonHealth::PoisonHealth(Tile *tile): Potion(tile, typeName) {}

bool PoisonHealth::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setHP(character->getHP() + ceil(EFFECT * multiplier));
        Potion::pickedUpBy(character);
    }
}

bool PoisonHealth::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    PoisonHealth::pickedUpBy(dynamic_cast<Character *>(drow));
}