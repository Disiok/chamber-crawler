// Cell
#include "wall.h"
#include "door.h"
#include "passage.h"
#include "tile.h"
#include "floor.h"

// Potion
#include "boostAtk.h"
#include "boostDef.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "poisonHealth.h"
#include "restoreHealth.h"

// Treasure
#include "smallTreasure.h"
#include "normalTreasure.h"
#include "merchantTreasure.h"
#include "dragonTreasure.h"

// Enemies
#include "entity.h"
#include "enemy.h"
#include "orc.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"

// Singletons
#include "player.h"
#include "stair.h"

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
	if (entity) {
		entity->performAction();
		return true;
	}
	return false;
}

bool Cell::isSteppable(Player *player) {
	return false;
}

bool Cell::isSteppable(Enemy *enemy) {
	return false;
}

Cell *Cell::getInstance(int i, int j, char id, Floor* floor) {
	// Returning Cells
	if (id == '|' || id == '-') {
		return new Wall(i, j, id, floor);
	} else if (id == '.') {
		return new Tile(i, j, floor);
	} else if (id == '#') {
		return new Passage(i, j, floor);
	} else if (id == '+') {
		return new Door(i, j, floor);
	}

	// Returning items
	if (id == '0') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new RestoreHealth(tile));
		return tile;
	} else if (id == '1') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new BoostAtk(tile));
		return tile;
	} else if (id == '2') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new BoostDef(tile));
		return tile;
	} else if (id == '3') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new PoisonHealth(tile));
		return tile;
	} else if (id == '4') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new WoundAtk(tile));
		return tile;
	} else if (id == '5') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new WoundDef(tile));
		return tile;
	} else if (id == '6') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new NormalTreasure(tile));
		return tile;
	} else if (id == '7') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new SmallTreasure(tile));
		return tile;
	} else if (id == '8') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new MerchantTreasure(tile));
		return tile;
	} else if (id == '9') {
		Tile *tile = new Tile(i, j, floor);
		// Spawn dragonTreasure without the dragon
		tile->setEntity(new DragonTreasure(tile, true));
		return tile;
	}

	// Returning enemies
	if (id == 'H') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new Human(tile));
		return tile;
	} else if (id == 'W') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new Dwarf(tile));
		return tile;
	} else if (id == 'E') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new Elf(tile));
		return tile;
	} else if (id == 'O') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new Orc(tile));
		return tile;
	} else if (id == 'M') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new Merchant(tile));
		return tile;
	} else if (id == 'D') {
		Tile *tile = new Tile(i, j, floor);
		tile->setEntity(new Dragon(tile, NULL));
		return tile;
	}

	// Returning singletons
	if (id == '@') {
		Tile *tile = new Tile(i, j, floor);
		tile->spawnPlayer();
		return tile;
	} else if (id == '\\') {
		Tile *tile = new Tile(i, j, floor);
		tile->spawnStair();
		return tile;
	}

	return NULL;
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
	clearEntity();
}

void Cell::clearEntity() {
	entity = NULL;
}

Entity *Cell::getEntity() {
	return entity;
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

bool Cell::pickedUpBy(Drow *drow) {
	if (entity) {
		return entity->pickedUpBy(drow);
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

Floor *Cell::getFloor() {
	return floor;
}

int Cell::getI() {
	return i;
}

int Cell::getJ() {
	return j;
}
