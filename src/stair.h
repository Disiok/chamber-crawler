#ifndef ___STAIR_H___
#define ___STAIR_H___
#include "entity.h"

// Forward declaration
class Character;
class Player;
class Tile;

class Stair: public Entity {
    private:
        static Stair *stairs;
        static void cleanup();

	public:
		Stair(Tile *tile);
        Stair *getInstance();
		bool steppedOnBy(Character *character);
		bool isSteppable(Player *player);
};
#endif
