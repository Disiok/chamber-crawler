#ifndef ___WOUNDATK_H___
#define ___WOUNDATK_H___
#include "potion.h"

class Cell;

class WoundAtk: public Potion {
    public:
        static const std::string typeIdentifier;
        WoundAtk(Tile *tile);
        bool pickedUpBy(Character *character);
        Player *getBarePlayer();
};
#endif