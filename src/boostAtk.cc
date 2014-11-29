#include "boostAtk.h"
using namespace std;

const string BoostAtk::typeIdentifier = "Boost Atk";

BoostAtk::BoostAtk(Tile *tile): Potion(tile, typeIdentifier) {}

bool BoostAtk::pickedUpBy(Character *character) {
    character->setAtk(character->getAtk() + 5);
    Potion::pickedUpBy(character);
}

Player *BoostAtk::getBarePlayer() {
    player->setAtk(player->getAtk() - 5);
    return Potion::getBarePlayer();
}