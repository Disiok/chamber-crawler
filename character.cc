#include "character.h"
#include "entity.h"
#include <string>
using namespace std;

Character::Character(Tile *tile, int hp, int atk, int def, int gold, char typeIdentifier, string typeName):
	Entity(tile),
	typeIdentifier(typeIdentifier),
	typeName(typeName),
	hp(hp),
	atk(atk),
	def(def),
	gold(gold) {}

Character::~Character() {}

void Character::attack(Character *character) {
	
}
bool Character::isAttacked(Character *character) {
	character->attack(this);
	return true;
}
