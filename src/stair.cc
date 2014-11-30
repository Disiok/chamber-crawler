#include "stair.h"
#include "player.h"
#include "tile.h"
#include "entity.h"
#include "game.h"
#include "character.h"
#include <cstdlib>
using namespace std;
Stair *Stair::stair = NULL;
const string Stair::NAME_STAIR = "Stair";

Stair::Stair(Tile *tile): Entity(tile) {}

void Stair::spawn(Tile *tile) {
    if (!stair) {
        stair = new Stair(tile);
	    atexit(cleanup);
    } else {
        stair->setCell(tile);
    }
}

Stair *Stair::getInstance() {
	return stair;
}

bool Stair::isSteppable(Player *) {
	return true;
}

bool Stair::steppedOnBy(Character *) {
	Game::getInstance()->signalNextFloor();
	return true;
}

void Stair::cleanup() {
	Cell *cell = stair->getCell();
	if (cell) {
		cell->clearEntity();
	}
	delete stair;
	stair = NULL;
}

char Stair::getSymbol() {
	return SYMBOL_STAIR;
}

string Stair::getName() {
	return NAME_STAIR;
}
