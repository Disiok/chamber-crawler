#ifndef ___POISONATK_H___
#define ___POISONATK_H___
#include "potion.h"

class Cell;

class PoisonHealth: public Potion {
    protected:
        static bool revealed;
        static const int EFFECT;
        double multiplier;
    public:
        static const std::string NAME_PH;
        static void resetRevealed();
        PoisonHealth(Tile *tile);
        bool pickedUpBy(Character *character);
        bool pickedUpBy(Drow *drow);

	// Entity method
	std::string getName();
};
#endif
