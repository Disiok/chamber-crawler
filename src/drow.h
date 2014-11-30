#ifndef ___DROW_H___
#define ___DROW_H___
#include <string>
#include "player.h"

// Forward declaration
class Tile;

class Drow: public Player {
	public:
		static const std::string NAME_DROW;
		static const char SYMBOL_DROW = 'D';
		
		static const int HP = 150;
		static const int ATK = 25;
		static const int DEF = 15;

		Drow(Tile *tile);
		bool attackedBy(Character *other);
		void pickUp(Cell *cell);

		// Entity methods
		std::string getName();
};
#endif
