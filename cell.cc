#include "cell.h"

// Forward Declaration
class Player;
class Enemy;

Cell::Cell(int i, int j):
	i(i), j(j) {}

Cell::~Cell() {}

bool isOccupied(Player *player) {
	return false;
}

bool isOccupied(Enemy *enemy) {
	return true;
}
