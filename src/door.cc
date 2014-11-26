#include "door.h"

Door::Door(int i, int j, Floor* floor):
	Cell(i, j, SYMBOL_DOOR, floor) {}

bool Door::isSteppable(Player *player) {
    return true;
}