#include "entity.h"
#include "tile.h"
#include "character.h"
#include "player.h"

Entity::Entity(Tile *tile): tile(tile) {
	tile->setEntity(this);	
}

Entity::~Entity() {}

void Entity::destroy() {
	tile->destroyEntity();
	tile->clearEntity();
}

void Entity::performAction() {}

bool Entity::steppedOnBy(Character *character) {
	return false;
}

bool Entity::attackedBy(Character *character) {
	return false;
}

bool Entity::pickedUpBy(Character *character) {
	return false;
}

bool Entity::isSteppable(Player *player) {
	return true;
}

bool Entity::isSteppable(Enemy *enemy) {
	return true;
}

Tile *Entity::getTile() {
	return tile;
}
