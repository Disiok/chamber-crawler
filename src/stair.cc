#include "stair.h"
#include "player.h"
#include "entity.h"
#include "character.h"

Stair *Stair::stairs = NULL;

Stair::Stair(Tile *tile): Entity(tile) {}

Stair *Stair::getInstance() {
    if (!stairs) {
        stairs = new Stairs();
    }
}

bool Stair::isSteppable(Player *player) {
	return true;
}

bool Stair::steppedOnBy(Character *Character) {
	// TODO: Add logic for player advancing
	return true;
}
