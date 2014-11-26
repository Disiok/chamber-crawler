#ifndef ___WALL_H___
#define ___WALL_H___
#include "cell.h"

// Forward declaration
class Player;

class Wall: public Cell {
	public:
		// Constructor
		Wall(int i, int j, char symbol, Floor* floor);
};
#endif
