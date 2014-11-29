#ifndef ___WOUNDATK_H___
#define ___WOUNDATK_H___
#include "potion.h"

class Cell;

class WoundAtk: public Potion {
    private:
        static bool revealed;
    public:
        static const std::string typeName;
        WoundAtk(Tile *tile);
        bool pickedUpBy(Character *character);
        Player *getBarePlayer();
};
#endif