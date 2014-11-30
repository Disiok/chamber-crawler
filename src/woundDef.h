#ifndef ___WOUNDDEF_H___
#define ___WOUNDDEF_H___
#include "potion.h"

class Cell;

class WoundDef: public Potion {
    private:
        static bool revealed;
        static const int EFFECT;
        double multiplier;
    public:
        static const std::string NAME_WD;
        static void resetRevealed();
        WoundDef(Tile *tile);
        bool pickedUpBy(Character *character);
        bool pickedUpBy(Drow *drow);
        Player *getBarePlayer();

	// Entity method
	std::string getName();
};
#endif
