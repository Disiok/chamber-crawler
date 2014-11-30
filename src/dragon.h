#ifndef ___DRAGON_H___
#define ___DRAGON_H___
#include "enemy.h"
#include <string>

class DragonTreasure;
class Character;
class Tile;

class Dragon: public Enemy {
    private:
        DragonTreasure *treasure;
    public:
        static const std::string NAME_DRAGON;
        static const char SYMBOL_DRAGON = 'D';
        static const int HP = 150;
        static const int ATK = 20;
        static const int DEF = 20;
        Dragon(Tile *tile, DragonTreasure *treasure);

        void move();
        bool isPlayerNearby();
        void killedBy(Character *other);
        void setTreasure(DragonTreasure *treasure);

	// Entity methods
	char getSymbol();
	std::string getName();
};

#endif
