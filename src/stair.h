#ifndef ___STAIR_H___
#define ___STAIR_H___
#include "entity.h"

// Forward declaration
class Character;
class Player;
class Tile;

class Stair: public Entity {
	private:
		static Stair *stair;
		static void cleanup();

		Stair(Tile *tile);

	public:
		static Stair *getInstance(Tile *tile);
		bool steppedOnBy(Character *character);
		bool isSteppable(Player *player);
};
#endif
