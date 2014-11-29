#include "boostDef.h"
using namespace std;

const string BoostDef::typeIdentifier = "Boost Def";

BoostDef::BoostDef(Tile *tile): Potion(tile, typeIdentifier) {}

void BoostDef::pickUp(Cell *cell) {
    player->setDef(player->getDef() + 5);
    Potion::pickUp(cell);
}

Player *BoostDef::getBarePlayer() {
    player->setDef(player->getDef() - 5);
    return Potion::getBarePlayer();
}