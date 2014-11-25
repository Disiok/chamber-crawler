#include "stair.h"
#include "player.h"
#include "entity.h"
#include "game.h"
#include "character.h"
#include <cstdlib>

Stair *Stair::stair = NULL;

Stair::Stair(Tile *tile): Entity(tile, SYMBOL_STAIR) {}

void Stair::spawn(Tile *tile) {
    if (!stair) {
        stair = new Stair(tile);
	atexit(cleanup);
    }
}

Stair *Stair::getInstance() {
	return stair;
}

bool Stair::isSteppable(Player *player) {
	return true;
}

bool Stair::steppedOnBy(Character *character) {
	Game::getInstance()->nextFloor();
	return true;
}

void Stair::cleanup() {
	delete stair;
}
