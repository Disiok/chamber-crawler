#include "orc.h"
#include "character.h"
#include "goblin.h"
#include <cmath>
#include <string>
using namespace std;

const string Orc::TYPE_NAME = "Orc";

Orc::Orc(Tile *tile): Enemy(tile, HP, ATK, DEF, TYPE_ID, TYPE_NAME) {}

int Orc::calculateDamageOn(Goblin *goblin) {
	return ceil(1.5 * Character::calculateDamageOn(goblin));
}

void Orc::attack(Goblin *goblin) {
    Character::attack(goblin);
}