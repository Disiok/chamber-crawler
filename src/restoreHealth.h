#ifndef ___RESTOREATK_H___
#define ___RESTOREATK_H___
#include "potion.h"

class Cell;

class RestoreHealth: public Potion {
    private:
        static bool revealed;
        static const int EFFECT;
        double multiplier;
    public:
        static const std::string NAME_RH;
        static void resetRevealed();
        RestoreHealth(Tile *tile);
        bool pickedUpBy(Character *character);
        bool pickedUpBy(Drow *drow);

	// Entity method
	std::string getName();
};
#endif
