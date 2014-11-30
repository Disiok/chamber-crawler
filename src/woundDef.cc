#include "woundDef.h"
#include "drow.h"
#include <cmath>
using namespace std;

const string WoundDef::NAME_WD = "Wound Def";
const int WoundDef::EFFECT = -5;
bool WoundDef::revealed = false;

void WoundDef::resetRevealed() {
    revealed = false;
}

WoundDef::WoundDef(Tile *tile): Potion(tile), multiplier(1) {}

bool WoundDef::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setDef(character->getDef() + ceil(EFFECT * multiplier));
        return Potion::pickedUpBy(character);
    }
    return false;
}

bool WoundDef::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    return WoundDef::pickedUpBy(dynamic_cast<Character *>(drow));
}

Player *WoundDef::getBarePlayer() {
    player->setDef(player->getDef() - ceil(EFFECT * multiplier));
    return Potion::getBarePlayer();
}

string WoundDef::getName() {
	return NAME_WD;
}
