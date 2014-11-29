#include "woundDef.h"

// temp
#include <iostream>
using namespace std;

const string WoundDef::typeIdentifier = "Wound Def";

WoundDef::WoundDef(Tile *tile): Potion(tile, typeIdentifier) {}

bool WoundDef::pickedUpBy(Character *character) {
    character->setDef(character->getDef() - 5);
    Potion::pickedUpBy(character);
}

Player *WoundDef::getBarePlayer() {
    player->setDef(player->getDef() + 5);
    return Potion::getBarePlayer();
}