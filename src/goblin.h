#ifndef ___GOBLIN_H___
#define ___GOBLIN_H___
#include <string>
#include "player.h"

// Forward declaration
class Tile;

class Goblin: public Player {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'G';
		static const int HP = 110;
		static const int ATK = 15;
		static const int DEF = 20;

		Goblin(Tile *tile);
		int calculateGoldFrom(Character *other);
        bool attackedBy(Character *other);
};
#endif
