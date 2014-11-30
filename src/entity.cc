#include "entity.h"
#include "tile.h"
#include "character.h"
#include "player.h"
#include <iostream>
using namespace std;

Entity::Entity(Tile *tile, char symbol): cell(tile), symbol(symbol) {}

Entity::~Entity() {}

void Entity::destroy() {
	cell->destroyEntity();
	cell->clearEntity();
}

void Entity::performAction() {}

bool Entity::steppedOnBy(Character *character) {
	return false;
}

bool Entity::attackedBy(Character *character) {
	return false;
}

bool Entity::attackedBy(Goblin *goblin) {
	return false;
}

bool Entity::pickedUpBy(Character *character) {
	return false;
}

bool Entity::pickedUpBy(Drow *drow) {
	return false;
}

bool Entity::isSteppable(Player *player) {
	return false;
}

bool Entity::isSteppable(Enemy *enemy) {
	return false;
}

Cell *Entity::getCell() {
	return cell;
}

char Entity::getSymbol() {
	return symbol;
}

void Entity::setCell(Cell *cell) {
	this->cell = cell;
}
