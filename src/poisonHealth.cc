#include "poisonHealth.h"
using namespace std;

const string PoisonHealth::typeName = "Poison Health";
bool PoisonHealth::revealed = false;

PoisonHealth::PoisonHealth(Tile *tile): Potion(tile, typeName) {}

bool PoisonHealth::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setHP(character->getHP() - 10);
        Potion::pickedUpBy(character);
    }
}