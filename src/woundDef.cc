#include "woundDef.h"
using namespace std;

const string WoundDef::typeIdentifier = "Wound Def";

WoundDef::WoundDef(Tile *tile): Potion(tile, typeIdentifier) {}

void WoundDef::pickUp(Cell *cell) {
    player->setDef(player->getDef() - 5);
    Potion::pickUp(cell);
}

Player *WoundDef::getBarePlayer() {
    player->setDef(player->getDef() + 5);
    return Potion::getBarePlayer();
}