#include "wall.h"

Wall::Wall(int i, int j, char symbol, Floor* floor):
	Cell(i, j, symbol, floor) {}