#ifndef ___PASSAGE_H___
#define ___PASSAGE_H___
#include "cell.h"

class Passage: public Cell {
	public:
		static const char SYMBOL_PASSAGE = '#';

		// Constructor
		Passage(int i, int j, Floor* floor);
        bool isSteppable(Player *player);
        char getSymbol();
};
#endif
