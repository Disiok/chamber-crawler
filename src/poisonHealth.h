#ifndef ___POISONATK_H___
#define ___POISONATK_H___
#include "potion.h"

class Cell;

class PoisonHealth: public Potion {
    public:
        static const std::string typeIdentifier;
        PoisonHealth(Tile *tile);
        bool pickedUpBy(Character *character);
};
#endif