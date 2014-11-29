#ifndef ___BOOSTATK_H___
#define ___BOOSTATK_H___
#include "potion.h"

class Cell;

class BoostAtk: public Potion {
    private:
        static bool revealed;
    public:
        static const std::string typeName;
        static void resetRevealed();
        BoostAtk(Tile *tile);
        bool pickedUpBy(Character *character);
        Player *getBarePlayer();
};
#endif