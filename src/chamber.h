#ifndef ___CHAMBER_H___
#define ___CHAMBER_H___
#include <vector>

// Forward declaration
class Cell;

class Chamber {
	private:
		std::vector<Cell *> chamberCells;
		int numCells;
	public:
		Chamber(std::vector<Cell *>& cells);
		Cell *getRandomCell();
};
#endif
