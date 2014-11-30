#ifndef ___WOUNDATK_H___
#define ___WOUNDATK_H___
#include "potion.h"

class Cell;

class WoundAtk: public Potion {
    private:
        static bool revealed;
        static const int EFFECT;
        double multiplier;
    public:
        static const std::string typeName;
        static void resetRevealed();
        WoundAtk(Tile *tile);
        bool pickedUpBy(Character *character);
        bool pickedUpBy(Drow *drow);
        Player *getBarePlayer();
};
#endif