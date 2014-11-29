#include "boostDef.h"
using namespace std;

const string BoostDef::typeName = "Boost Def";
bool BoostDef::revealed = false;

void BoostDef::resetRevealed() {
    revealed = false;
}

BoostDef::BoostDef(Tile *tile): Potion(tile, typeName) {}

bool BoostDef::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setDef(character->getDef() + 5);
        Potion::pickedUpBy(character);
    }
}

Player *BoostDef::getBarePlayer() {
    player->setDef(player->getDef() - 5);
    return Potion::getBarePlayer();
}