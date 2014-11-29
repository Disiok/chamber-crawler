#ifndef ___WOUNDDEF_H___
#define ___WOUNDDEF_H___
#include "potion.h"

class Cell;

class WoundDef: public Potion {
    public:
        static const std::string typeIdentifier;
        WoundDef(Tile *tile);
        bool pickedUpBy(Character *character);
        Player *getBarePlayer();
};
#endif