#include "boostAtk.h"
#include "drow.h"
#include <cmath>
using namespace std;

const string BoostAtk::typeName = "Boost Atk";
const int BoostAtk::EFFECT = 5;
bool BoostAtk::revealed = false;

void BoostAtk::resetRevealed() {
    revealed = false;
}

BoostAtk::BoostAtk(Tile *tile): Potion(tile, typeName), multiplier(1) {}

bool BoostAtk::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setAtk(character->getAtk() + ceil(EFFECT * multiplier));
        return Potion::pickedUpBy(character);
    } else {
    	return false;
    }
}

bool BoostAtk::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    return BoostAtk::pickedUpBy(dynamic_cast<Character *>(drow));
}

Player *BoostAtk::getBarePlayer() {
    player->setAtk(player->getAtk() - ceil(EFFECT * multiplier));
    return Potion::getBarePlayer();
}
