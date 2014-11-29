#ifndef ___WOUNDDEF_H___
#define ___WOUNDDEF_H___
#include "potion.h"

class Cell;

class WoundDef: public Potion {
    public:
        static const std::string typeIdentifier;
        WoundDef(Tile *tile);
        void pickUp(Cell *cell);
        Player *getBarePlayer();
};
#endif