#ifndef ___STAIR_H___
#define ___STAIR_H___
#include "entity.h"

// Forward declaration
class Character;
class Player;

class Stair: public Entity {
	public:
		bool isSteppedOn(Character *character);
		bool isOccupied(Player *player);
};
#endif
