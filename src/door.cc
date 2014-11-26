#include "door.h"

Door::Door(int i, int j ):
	Cell(i, j, SYMBOL_DOOR) {}

bool Door::isSteppable(Player *player) {
    return true;
}