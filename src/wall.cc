#include "wall.h"

Wall::Wall(int i, int j, char symbol):
	Cell(i, j, symbol) {}
	
bool Wall::isSteppable(Player *player) {
	return true;
}
