#ifndef ___WOUNDATK_H___
#define ___WOUNDATK_H___
#include "potion.h"

class Cell;

class WoundAtk: public Potion {
    public:
        static const std::string typeIdentifier;
        WoundAtk(Tile *tile);
        void pickUp(Cell *cell);
        Player *getBarePlayer();
};
#endif