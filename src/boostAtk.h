#ifndef ___BOOSTATK_H___
#define ___BOOSTATK_H___
#include "potion.h"

class Cell;

class BoostAtk: public Potion {
    private:
        static bool revealed;
        static const int EFFECT;
        double multiplier;
    public:
        static const std::string NAME_BA;
        static void resetRevealed();
        BoostAtk(Tile *tile);
        bool pickedUpBy(Character *character);
        bool pickedUpBy(Drow *drow);
        Player *getBarePlayer();
	
	// Entity method
	std::string getName();
};
#endif
