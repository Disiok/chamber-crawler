#ifndef ___STAIR_H___
#define ___STAIR_H___
#include "entity.h"
#include <string>

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
		static const char SYMBOL_STAIR = '\\';
		static const std::string NAME_STAIR;

		static void spawn(Tile *tile);
		static Stair *getInstance();
		bool steppedOnBy(Character *character);
		bool isSteppable(Player *player);

		// Entity methods
		char getSymbol();
		std::string getName();
};
#endif
