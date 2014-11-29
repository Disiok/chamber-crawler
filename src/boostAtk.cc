#include "boostAtk.h"
using namespace std;

const string BoostAtk::typeIdentifier = "Boost Atk";

BoostAtk::BoostAtk(Tile *tile): Potion(tile, typeIdentifier) {}

void BoostAtk::pickUp(Cell *cell) {
    player->setAtk(player->getAtk() + 5);
    Potion::pickUp(cell);
}

Player *BoostAtk::getBarePlayer() {
    player->setAtk(player->getAtk() - 5);
    return Potion::getBarePlayer();
}