#ifndef ___RESTOREATK_H___
#define ___RESTOREATK_H___
#include "potion.h"

class Cell;

class RestoreHealth: public Potion {
    private:
        static bool revealed;
    public:
        static const std::string typeName;
        static void resetRevealed();
        RestoreHealth(Tile *tile);
        bool pickedUpBy(Character *character);
};
#endif