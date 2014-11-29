#include "woundAtk.h"
using namespace std;

const string WoundAtk::typeIdentifier = "Wound Atk";

WoundAtk::WoundAtk(Tile *tile): Potion(tile, typeIdentifier) {}

void WoundAtk::pickUp(Cell *cell) {
    player->setAtk(player->getAtk() - 5);
    Potion::pickUp(cell);
}

Player *WoundAtk::getBarePlayer() {
    player->setAtk(player->getAtk() + 5);
    return Potion::getBarePlayer();
}