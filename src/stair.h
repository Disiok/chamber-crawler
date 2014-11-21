#ifndef ___STAIR_H___
#define ___STAIR_H___
#include "entity.h"

// Forward declaration
class Character;
class Player;
class Tile;

class Stair: public Entity {
	public:
		Stair(Tile *tile);
		
		bool steppedOnBy(Character *character);
		bool isSteppable(Player *player);
};
#endif
