#include "boostDef.h"
#include "drow.h"
#include <cmath>
#include <iostream>
using namespace std;

const string BoostDef::NAME_BD = "Boost Def";
const int BoostDef::EFFECT = 5;
bool BoostDef::revealed = false;

void BoostDef::resetRevealed() {
    revealed = false;
}

BoostDef::BoostDef(Tile *tile): Potion(tile), multiplier(1) {}

bool BoostDef::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setDef(character->getDef() + ceil(EFFECT * multiplier));
        return Potion::pickedUpBy(character);
    }
    return false;
}

bool BoostDef::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    return BoostDef::pickedUpBy(dynamic_cast<Character *>(drow));
}


Player *BoostDef::getBarePlayer() {
    player->setDef(player->getDef() - ceil(EFFECT * multiplier));
    return Potion::getBarePlayer();
}

string BoostDef::getName() {
	return NAME_BD;
}
