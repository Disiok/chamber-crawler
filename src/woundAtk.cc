#include "woundAtk.h"
#include "drow.h"
#include <cmath>
using namespace std;

const string WoundAtk::typeName = "Wound Atk";
const int WoundAtk::EFFECT = -5;
bool WoundAtk::revealed = false;

void WoundAtk::resetRevealed() {
    revealed = false;
}

WoundAtk::WoundAtk(Tile *tile): Potion(tile, typeName), multiplier(1) {}

bool WoundAtk::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setAtk(character->getAtk() + ceil(EFFECT * multiplier));
        Potion::pickedUpBy(character);
    }
}

bool WoundAtk::pickedUpBy(Drow *drow) {
    multiplier = 1.5;
    WoundAtk::pickedUpBy(dynamic_cast<Character *>(drow));
}

Player *WoundAtk::getBarePlayer() {
    player->setAtk(player->getAtk() - ceil(EFFECT * multiplier));
    return Potion::getBarePlayer();
}