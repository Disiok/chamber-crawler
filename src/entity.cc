#include "entity.h"
#include "tile.h"
#include "character.h"
#include "player.h"
#include <iostream>
using namespace std;

// Constructor & destructor
Entity::Entity(Tile *tile, char symbol): cell(tile) {}

Entity::~Entity() {}

// Methods
void Entity::performAction() {}

bool Entity::steppedOnBy(Character *) {
	return false;
}

bool Entity::attackedBy(Character *) {
	return false;
}

bool Entity::attackedBy(Goblin *) {
	return false;
}

bool Entity::pickedUpBy(Character *) {
	return false;
}

bool Entity::pickedUpBy(Drow *) {
	return false;
}

bool Entity::isSteppable(Player *) {
	return false;
}

bool Entity::isSteppable(Enemy *) {
	return false;
}

// Accessors
Cell *Entity::getCell() {
	return cell;
}

// Mutator
void Entity::setCell(Cell *cell) {
	this->cell = cell;
}
