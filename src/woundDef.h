#ifndef ___WOUNDDEF_H___
#define ___WOUNDDEF_H___
#include "potion.h"

class Cell;

class WoundDef: public Potion {
    private:
        static bool revealed;
    public:
        static const std::string typeName;
        static void resetRevealed();
        WoundDef(Tile *tile);
        bool pickedUpBy(Character *character);
        Player *getBarePlayer();
};
#endif