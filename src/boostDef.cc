#include "boostDef.h"
using namespace std;

const string BoostDef::typeIdentifier = "Boost Def";

BoostDef::BoostDef(Tile *tile): Potion(tile, typeIdentifier) {}

bool BoostDef::pickedUpBy(Character *character) {
    character->setDef(character->getDef() + 5);
    Potion::pickedUpBy(character);
}

Player *BoostDef::getBarePlayer() {
    player->setDef(player->getDef() - 5);
    return Potion::getBarePlayer();
}