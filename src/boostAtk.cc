#include "boostAtk.h"
using namespace std;

const string BoostAtk::typeName = "Boost Atk";
bool BoostAtk::revealed = false;

BoostAtk::BoostAtk(Tile *tile): Potion(tile, typeName) {}

bool BoostAtk::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setAtk(character->getAtk() + 5);
        Potion::pickedUpBy(character);
    }
}

Player *BoostAtk::getBarePlayer() {
    player->setAtk(player->getAtk() - 5);
    return Potion::getBarePlayer();
}