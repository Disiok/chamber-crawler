#include "poisonHealth.h"
using namespace std;

const string PoisonHealth::typeIdentifier = "Poison Health";

PoisonHealth::PoisonHealth(Tile *tile): Potion(tile, typeIdentifier) {}

bool PoisonHealth::pickedUpBy(Character *character) {
    character->setHP(character->getHP() - 10);
    Potion::pickedUpBy(character);
}