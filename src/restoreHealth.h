#ifndef ___RESTOREATK_H___
#define ___RESTOREATK_H___
#include "potion.h"

class Cell;

class RestoreHealth: public Potion {
    public:
        static const std::string typeIdentifier;
        RestoreHealth(Tile *tile);
        bool pickedUpBy(Character *character);
};
#endif