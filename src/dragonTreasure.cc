#include "dragonTreasure.h"

DragonTreasure::DragonTreasure(Tile *tile): Treasure(tile, GOLD_DRAGON), isGuarded(true) {
	// TODO: Spawn a dragon when the treasure spawns
}

bool DragonTreasure::isSteppable(Player *player) {
	return !isGuarded;
}

