#include "wall.h"
#include "door.h"
#include "passage.h"
#include "entity.h"
#include "tile.h"
#include "enemy.h"
#include "floor.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// Forward Declaration
class Player;
class Enemy;

Cell::Cell(int i, int j, char symbol, Floor *floor):
	i(i), j(j), symbol(symbol), entity(NULL), floor(floor) {}

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

Cell *Cell::getInstance(int i, int j, char id, Floor* floor) {
	if (id == '|' || id == '-') {
		return new Wall(i, j, id, floor);
	} else if (id == '.') {
		return new Tile(i, j, floor);
	} else if (id == '#') {
		return new Passage(i, j, floor);
	} else if (id == '+') {
		return new Door(i, j, floor);
	} else {
		return NULL;
	}
}

bool Cell::hasEntity() {
	if (entity) {
		return true;
	} else {
		return false;
	}
}
void Cell::destroyEntity() {
	delete entity;
}

void Cell::clearEntity() {
	entity = NULL;
}

void Cell::setEntity(Entity *entity) {
	this->entity = entity;
}

bool Cell::steppedOnBy(Character *other) {
	if (entity) {
		return entity->steppedOnBy(other);
	} else {
		return false;
	}
}

bool Cell::pickedUpBy(Character *other) {
	if (entity) {
		return entity->pickedUpBy(other);
	} else {
		return false;
	}
}

bool Cell::attackedBy(Character *other) {
	if (entity) {
		return entity->attackedBy(other);
	} else {
		return false;
	}
}

char Cell::getSymbol() {
	if (entity) {
		return entity->getSymbol();
	} else {
		return symbol;
	}
}

int Cell::getI() {
	return i;
}

int Cell::getJ() {
	return j;
}
