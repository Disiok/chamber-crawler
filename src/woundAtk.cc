#include "woundAtk.h"
using namespace std;

const string WoundAtk::typeName = "Wound Atk";
bool WoundAtk::revealed = false;

void WoundAtk::resetRevealed() {
    revealed = false;
}

WoundAtk::WoundAtk(Tile *tile): Potion(tile, typeName) {}

bool WoundAtk::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setAtk(character->getAtk() - 5);
        Potion::pickedUpBy(character);
    }
}

Player *WoundAtk::getBarePlayer() {
    player->setAtk(player->getAtk() + 5);
    return Potion::getBarePlayer();
}