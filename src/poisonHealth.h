#ifndef ___POISONATK_H___
#define ___POISONATK_H___
#include "potion.h"

class Cell;

class PoisonHealth: public Potion {
    private:
        static bool revealed;
    public:
        static const std::string typeName;
        PoisonHealth(Tile *tile);
        bool pickedUpBy(Character *character);
};
#endif