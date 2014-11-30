#include "woundAtk.h"
#include "drow.h"
#include <cmath>
using namespace std;

const string WoundAtk::NAME_WA = "Wound Atk";
const int WoundAtk::EFFECT = -5;
bool WoundAtk::revealed = false;

void WoundAtk::resetRevealed() {
    revealed = false;
}

WoundAtk::WoundAtk(Tile *tile): Potion(tile), multiplier(1) {}

bool WoundAtk::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setAtk(character->getAtk() + ceil(EFFECT * multiplier));
        return Potion::pickedUpBy(character);
    }
    return false;
}

bool WoundAtk::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    return WoundAtk::pickedUpBy(dynamic_cast<Character *>(drow));
}

Player *WoundAtk::getBarePlayer() {
    player->setAtk(player->getAtk() - ceil(EFFECT * multiplier));
    return Potion::getBarePlayer();
}

string WoundAtk::getName() {
	return NAME_WA;
}
