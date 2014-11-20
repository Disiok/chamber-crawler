#include "entity.h"
#include "tile.h"
#include "character.h"
#include "player.h"

Entity::Entity(Tile *tile): tile(tile) {
	tile->setEntity(this);	
}

Entity::~Entity() {}

void Entity::destroy() {
	tile->clearEntity();
}

void Entity::performAction() {}

bool Entity::isSteppedOn(Character *character) {
	return false;
}

bool Entity::isAttacked(Character *character) {
	return false;
}

bool Entity::isPickedUp(Character *character) {
	return false;
}

bool Entity::isOccupied(Player *player) {
	return true;
}

bool Entity::isOccupied(Enemy *enemy) {
	return true;
}
