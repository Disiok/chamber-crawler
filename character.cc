#include "character.h"
#include "entity.h"
#include <string>
using namespace std;

Character::Character(Tile *tile, int healthPoint, int attack, int defense, int gold, char typeIdentifier, string typeName):
	Entity(tile),
	typeIdentifier(typeIdentifier),
	typeName(typeName),
	healthPoint(healthPoint),
	attack(attack),
	defense(defense),
	gold(gold) {}

Character::~Character() {}

void Character::attack(Character *character) {
	
}
bool Character::isAttacked(Character *character) {
	character.attack(this);
	return true;
}
