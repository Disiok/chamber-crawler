#ifndef ___DROW_H___
#define ___DROW_H___
#include <string>
#include "player.h"

// Forward declaration
class Tile;

class Drow: public Player {
	public:
		static const std::string TYPE_NAME;
		static const char TYPE_ID = 'D';
		static const int HP = 1;
		static const int ATK = 25;
		static const int DEF = 15;

		Drow(Tile *tile);
        bool attackedBy(Character *other);
};
#endif
