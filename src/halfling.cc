#include "halfling.h"
#include <string>
#include <cstdlib>
using namespace std;

const string Halfling::TYPE_NAME = "Halfling";

Halfling::Halfling(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}

bool Halfling::attackedBy(Character *other) {
	if (rand() % 2) {
		Character::attackedBy(other);
	} else {
		other->addMissAction(this);
	}
	return true;
}
