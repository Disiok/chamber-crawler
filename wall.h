#ifndef ___WALL_H___
#define ___WALL_H___
#include "cell.h"

// Forward declaration
class Player;

class Wall: public Cell {
	public:
		static const char SYMBOL_WALL = '|';
		
		// Constructor
		Wall(int i, int j);
		bool isOccupied(Player *player);
};
#endif
