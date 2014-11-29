#ifndef ___BOOSTDEF_H___
#define ___BOOSTDEF_H___
#include "potion.h"

class Cell;

class BoostDef: public Potion {
    private:
        static bool revealed;
    public:
        static const std::string typeName;
        static void resetRevealed();
        BoostDef(Tile *tile);
        bool pickedUpBy(Character *character);
        Player *getBarePlayer();
};
#endif