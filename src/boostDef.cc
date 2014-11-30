#include "boostDef.h"
#include "drow.h"
#include <cmath>
#include <iostream>
using namespace std;

const string BoostDef::typeName = "Boost Def";
const int BoostDef::EFFECT = 5;
bool BoostDef::revealed = false;

void BoostDef::resetRevealed() {
    revealed = false;
}

BoostDef::BoostDef(Tile *tile): Potion(tile, typeName), multiplier(1) {}

bool BoostDef::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setDef(character->getDef() + ceil(EFFECT * multiplier));
        Potion::pickedUpBy(character);
    }
}

bool BoostDef::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    BoostDef::pickedUpBy(dynamic_cast<Character *>(drow));
}


Player *BoostDef::getBarePlayer() {
    player->setDef(player->getDef() - ceil(EFFECT * multiplier));
    return Potion::getBarePlayer();
}