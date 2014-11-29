#include "woundDef.h"
using namespace std;

const string WoundDef::typeName = "Wound Def";
bool WoundDef::revealed = false;

WoundDef::WoundDef(Tile *tile): Potion(tile, typeName) {}

bool WoundDef::pickedUpBy(Character *character) {
    if (choosePickUp(revealed)) {
        revealed = true;
        character->setDef(character->getDef() - 5);
        Potion::pickedUpBy(character);
    }
}

Player *WoundDef::getBarePlayer() {
    player->setDef(player->getDef() + 5);
    return Potion::getBarePlayer();
}