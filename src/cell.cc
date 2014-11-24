#include "cell.h"
#include "wall.h"
#include "door.h"
#include "passage.h"
#include "tile.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Forward Declaration
class Player;
class Enemy;

Cell::Cell(int i, int j, char symbol):
	i(i), j(j), symbol(symbol) {}

Cell::~Cell() {}

bool Cell::performAction() {
	return false;
}

bool Cell::isSteppable(Player *player) {
	return false;
}

bool Cell::isSteppable(Enemy *enemy) {
	return true;
}

Cell *Cell::getInstance(int i, int j, char id) {
	if (id == '|' || id == '-') {
		return new Wall(i, j, id);
	} else if (id == '.') {
		return new Tile(i, j);
	} else if (id == '#') {
		return new Passage(i, j);
	} else if (id == '+') {
		return new Door(i, j);
	} else {
		return NULL;
	}
}

char Cell::getSymbol() {
	return symbol;
}
