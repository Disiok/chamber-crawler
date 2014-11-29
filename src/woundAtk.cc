#include "woundAtk.h"
using namespace std;

const string WoundAtk::typeIdentifier = "Wound Atk";

WoundAtk::WoundAtk(Tile *tile): Potion(tile, typeIdentifier) {}

bool WoundAtk::pickedUpBy(Character *character) {
    character->setAtk(character->getAtk() - 5);
    Potion::pickedUpBy(character);
}

Player *WoundAtk::getBarePlayer() {
    player->setAtk(player->getAtk() + 5);
    return Potion::getBarePlayer();
}