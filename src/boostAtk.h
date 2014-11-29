#ifndef ___BOOSTATK_H___
#define ___BOOSTATK_H___
#include "potion.h"

class Cell;

class BoostAtk: public Potion {
    public:
        static const std::string typeIdentifier;
        BoostAtk(Tile *tile);
        void pickUp(Cell *cell);
        Player *getBarePlayer();
};
#endif