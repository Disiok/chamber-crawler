#include "passage.h"

Passage::Passage(int i, int j, Floor* floor):
	Cell(i, j, SYMBOL_PASSAGE, floor) {}

bool Passage::isSteppable(Player *player) {
    return true;
}