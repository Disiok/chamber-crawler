#ifndef ___POISONATK_H___
#define ___POISONATK_H___
#include "potion.h"

class Cell;

class PoisonHealth: public Potion {
    protected:
        static bool revealed;
    public:
        static const std::string typeName;
        static void resetRevealed();
        PoisonHealth(Tile *tile);
        bool pickedUpBy(Character *character);
};
#endif