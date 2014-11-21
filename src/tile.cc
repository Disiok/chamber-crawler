#include "tile.h"
#include "entity.h"

Tile::Tile(int i, int j):
	Cell(i, j, SYMBOL_TILE), entity(0) {}

void Tile::destroyEntity() {
	delete entity;
}

void Tile::clearEntity() {
	entity = 0;
}

void Tile::setEntity(Entity *entity) {
	this->entity = entity;
}
