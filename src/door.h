#ifndef ___DOOR_H___
#define ___DOOR_H___
#include "cell.h"

class Door: public Cell {
	public:
		static const char SYMBOL_DOOR = '+';

		// Constructor
		Door(int i, int j, Floor* floor);
        bool isSteppable(Player *player);
        char getSymbol();
};
#endif
