#ifndef ___BOOSTDEF_H___
#define ___BOOSTDEF_H___
#include "potion.h"

class Cell;

class BoostDef: public Potion {
    public:
        static const std::string typeIdentifier;
        BoostDef(Tile *tile);
        bool pickedUpBy(Character *character);
        Player *getBarePlayer();
};
#endif