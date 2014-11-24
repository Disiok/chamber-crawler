#include "tile.h"
#include "entity.h"
#include "enemy.h"
#include "character.h"
#include <iostream>
using namespace std;

Tile::Tile(int i, int j):
	Cell(i, j, SYMBOL_TILE), entity(NULL) {}

void Tile::destroyEntity() {
	delete entity;
}

void Tile::clearEntity() {
	entity = NULL;
}

void Tile::setEntity(Entity *entity) {
	this->entity = entity;
}

bool Tile::steppedOnBy(Character *other) {
	if (entity) {
		return entity->steppedOnBy(other);
	} else {
		return false;
	}
}

bool Tile::pickedUpBy(Character *other) {
	if (entity) {
		return entity->pickedUpBy(other);
	} else {
		return false;
	}
}

bool Tile::attackedBy(Character *other) {
	if (entity) {
		return entity->attackedBy(other);
	} else {
		return false;
	}
}

bool Tile::isSteppable(Player *player) {
	if (entity) {
		return entity->isSteppable(player);
	} else {
		return true;
	}
}

bool Tile::isSteppable(Enemy *enemy) {
	if (entity) {
		return entity->isSteppable(enemy);
	} else {
		return true;
	}
}

char Tile::getSymbol() {
	if (entity) {
		return entity->getSymbol();
	} else {
		return Cell::getSymbol();
	}
}
