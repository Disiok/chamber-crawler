#ifndef ___BOOSTDEF_H___
#define ___BOOSTDEF_H___
#include "potion.h"

class Cell;

class BoostDef: public Potion {
    private:
        static bool revealed;
        static const int EFFECT;
        double multiplier;
    public:
        static const std::string NAME_BD;
        static void resetRevealed();
        BoostDef(Tile *tile);
        bool pickedUpBy(Character *character);
        bool pickedUpBy(Drow *drow);
        Player *getBarePlayer();

	// Entity method
	std::string getName();
};
#endif
