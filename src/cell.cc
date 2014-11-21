#include "cell.h"

// Forward Declaration
class Player;
class Enemy;

Cell::Cell(int i, int j, char symbol):
	i(i), j(j), symbol(symbol) {}

Cell::~Cell() {}

bool Cell::isOccupied(Player *player) {
	return false;
}

bool Cell::isOccupied(Enemy *enemy) {
	return true;
}
