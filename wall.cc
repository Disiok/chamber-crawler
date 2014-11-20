#include "wall.h"

Wall::Wall(int i, int j):
	Cell(i, j, SYMBOL_WALL) {}
	
bool Wall::isOccupied(Player *player) {
	return true;
}
